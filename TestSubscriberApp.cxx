// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file TestSubscriberApp.cxx
 * This file contains the implementation of the subscriber functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#include "TestSubscriberApp.hpp"

#include <condition_variable>
#include <stdexcept>

#include <fastdds/dds/core/status/SubscriptionMatchedStatus.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/qos/SubscriberQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include "TestPubSubTypes.hpp"

using namespace eprosima::fastdds::dds;

TestSubscriberApp::TestSubscriberApp(
        const int& domain_id)
    : factory_(nullptr)
    , participant_(nullptr)
    , subscriber_(nullptr)
    , topic_(nullptr)
    , reader_(nullptr)
    , type_(new TestPubSubType())
    , samples_received_(0)
    , stop_(false)
{
    // Create the participant
    DomainParticipantQos pqos = PARTICIPANT_QOS_DEFAULT;
    pqos.name("Test_sub_participant");
    factory_ = DomainParticipantFactory::get_shared_instance();
    participant_ = factory_->create_participant(domain_id, pqos, nullptr, StatusMask::none());
    if (participant_ == nullptr)
    {
        throw std::runtime_error("Test Participant initialization failed");
    }

    // Register the type
    type_.register_type(participant_);

    // Create the subscriber
    SubscriberQos sub_qos = SUBSCRIBER_QOS_DEFAULT;
    participant_->get_default_subscriber_qos(sub_qos);
    subscriber_ = participant_->create_subscriber(sub_qos, nullptr, StatusMask::none());
    if (subscriber_ == nullptr)
    {
        throw std::runtime_error("Test Subscriber initialization failed");
    }

    // Create the topic
    TopicQos topic_qos = TOPIC_QOS_DEFAULT;
    participant_->get_default_topic_qos(topic_qos);
    topic_ = participant_->create_topic("TestTopic", type_.get_type_name(), topic_qos);
    if (topic_ == nullptr)
    {
        throw std::runtime_error("Test Topic initialization failed");
    }

    // Create the reader
    DataReaderQos reader_qos = DATAREADER_QOS_DEFAULT;
    subscriber_->get_default_datareader_qos(reader_qos);
    reader_qos.reliability().kind = ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
    reader_qos.durability().kind = DurabilityQosPolicyKind::TRANSIENT_LOCAL_DURABILITY_QOS;
    reader_qos.history().kind = HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
    reader_ = subscriber_->create_datareader(topic_, reader_qos, this, StatusMask::all());
    if (reader_ == nullptr)
    {
        throw std::runtime_error("Test DataReader initialization failed");
    }
}

TestSubscriberApp::~TestSubscriberApp()
{
    if (nullptr != participant_)
    {
        // Delete DDS entities contained within the DomainParticipant
        participant_->delete_contained_entities();

        // Delete DomainParticipant
        factory_->delete_participant(participant_);
    }
}

void TestSubscriberApp::on_subscription_matched(
        DataReader* /*reader*/,
        const SubscriptionMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        std::cout << "Test Subscriber matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        std::cout << "Test Subscriber unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
    }
}

  // In subscriber, you could also display the message content:
  void TestSubscriberApp::on_data_available(DataReader* reader)
  {
      Test sample_;
      SampleInfo info;
      while ((!is_stopped()) && (RETCODE_OK == reader->take_next_sample(&sample_, &info)))  
      {
          if ((info.instance_state == ALIVE_INSTANCE_STATE) && info.valid_data)
          {
              std::cout << "Received raw message: " << sample_.msg() << std::endl;
              
              // Parse the string back into KeyDataModule (optional)
              try {
                  std::string msg = sample_.msg();
                  size_t k1_pos = msg.find("k1:");
                  size_t k2_pos = msg.find("k2:");
                  size_t k3_pos = msg.find("k3:");
                  
                  int k1 = std::stoi(msg.substr(k1_pos+3, msg.find(',', k1_pos)-(k1_pos+3)));
                  int k2 = std::stoi(msg.substr(k2_pos+3, msg.find(',', k2_pos)-(k2_pos+3)));
                  int k3 = std::stoi(msg.substr(k3_pos+3));
                  
                  std::cout << "Parsed values - k1: " << k1 
                            << ", k2: " << k2 
                            << ", k3: " << k3 << std::endl;
              }
              catch (...) {
                  std::cerr << "Error parsing message" << std::endl;
              }
          }
      }
  }

void TestSubscriberApp::run()
{
    std::unique_lock<std::mutex> lck(terminate_cv_mtx_);
    terminate_cv_.wait(lck, [this]
            {
                return is_stopped();
            });
}

bool TestSubscriberApp::is_stopped()
{
    return stop_.load();
}

void TestSubscriberApp::stop()
{
    stop_.store(true);
    terminate_cv_.notify_all();
}