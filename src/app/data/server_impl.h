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
// Date: $time$
#ifndef __APP_DATA_SERVER_IMPL_H_
#define __APP_DATA_SERVER_IMPL_H_



#include <gflags/gflags.h>
#include "data.pb.h"
#include <brpc/server.h>
#include "data_manager.h"


// Your implementation of data::user::GetUserInfoService
// Notice that implementing brpc::Describable grants the ability to put
// additional information in /status.
namespace antalk {
namespace data {
	
class UserStatusServiceImpl : public UserStatusService {
public:
	UserStatusServiceImpl() {};
	virtual ~UserStatusServiceImpl() {};
    virtual void GetUserInfo(google::protobuf::RpcController* cntl_base,
        const GetUserInfoReq* request,
        GetUserInfoRes* response,
        google::protobuf::Closure* done);
};

}  // namespace example
}

#endif
