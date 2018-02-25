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

#include "cache_manager.h"

namespace antalk {
namespace data {

CacheManager& CacheManager::Instance() {
	static CacheManager g_cache_manager;
	return g_cache_manager;
}

CacheManager::CacheManager() {}

CacheManager::~CacheManager() {}

bool CacheManager::Init() {
    brpc::ChannelOptions options;
    options.protocol = brpc::PROTOCOL_REDIS;
	if (channel_.Init(ServerConfig::Instance().GetRedisServer().c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return false;
	}    
	return true;
}

bool CacheManager::AccessRedis(brpc::Channel& channel, const std::string& command) {
	brpc::RedisRequest request;
	if (!request.AddCommand(command.c_str())) {
        LOG(ERROR) << "Fail to AddCommand command";
        return false;
	}

	brpc::RedisResponse response;
	brpc::Controller cntl;
	channel.CallMethod(NULL, &cntl, &request, &response, NULL);
	if (cntl.Failed()) {
        LOG(ERROR) << "Fail to CallMethod to redis";
        return false;
	}

	//response.reply()

	return true;
}

bool CacheManager::GetUserinfo(const std::string& saas_id,
		                       const std::string& user_id,
                               antalk::common::UserInfo& user_info) {
	std::string command = "";
    return true;
}

}
}

