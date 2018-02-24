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
#ifndef SRC_APP_DATA_CACHE_MANAGER_H_
#define SRC_APP_DATA_CACHE_MANAGER_H_

#include <string>
#include <brpc/channel.h>
#include <brpc/redis.h>
#include "common.pb.h"
#include "server_config.h"

namespace antalk {
namespace data {

#define KEY_USERINFO	"antalk:userinfo:ssid:%s:userid:%s"


class CacheManager {
public:
	static CacheManager& Instance();
    bool Init(); 
	bool GetUserinfo(const std::string& saas_id, const std::string& user_id, antalk::common::UserInfo& user_info);

private:
	CacheManager();
	~CacheManager();
	bool AccessRedis(brpc::Channel& channel, const std::string& command);

private:
    brpc::Channel channel_;
};

}
}



#endif /* SRC_APP_DATA_CACHE_MANAGER_H_ */
