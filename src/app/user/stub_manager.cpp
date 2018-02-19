// Copyright (c) 2015 Antalk, Inc.
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

// Author: chenbang@antalk.com

#include "stub_manager.h"

namespace antalk {
namespace user {

DEFINE_string(datasvr_nameservice, "file://datasvr_lists", "Lists of IP:PORT of datasvrs");
DEFINE_string(datasvr_loadbalancer, "", "The algorithm for load balancing");

StubManager& StubManager::Instance() {
	static StubManager g_stub_mgr;
	return g_stub_mgr;
}

bool StubManager::Init() {
	// A Channel represents a communication line to a Server. Notice that
	// Channel is thread-safe and can be shared by all threads in your program.
	brpc::Channel datasvr_channel;
	brpc::ChannelOptions datasvr_channel_options;
	if (!datasvr_channel.Init(FLAGS_datasvr_nameservice.c_str(),
			                  FLAGS_datasvr_loadbalancer.c_str(),
							  &datasvr_channel_options)) {
        LOG(ERROR) << "Fail to initialize datasvr_channel";
        return false;
	}

	getuserinfo_stub_ =  new data::user::GetUserInfoService_Stub(&datasvr_channel);

	return true;
}





}}
