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

// Author: chenbang (chenbang@antalk.com)

#ifndef _DEP_DB_REDIS_CMD_STRING_H_
#define _DEP_DB_REDIS_CMD_STRING_H_

#include <string>
#include "redis_cmd.h"

namespace anrpc {
namespace redis {

class RedisCmdString : public RedisCmd {
public:
    virtual RedisResultPtr Run(const RedisRequest& req) = 0;

    //如果SET命令正常执行那么返回OK，否则如果加了NX 或者 XX选项，但是没有设置条件。那么会返回nil
    const std::string Set(const std::string& key, const std::string& value);
};

}
}
#endif