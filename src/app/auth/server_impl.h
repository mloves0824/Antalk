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
#ifndef __APP_USER_SERVER_IMPL_H_
#define __APP_USER_SERVER_IMPL_H_


#include <gflags/gflags.h>
#include <brpc/server.h>
#include <brpc/channel.h>
#include "auth.pb.h"

// Your implementation of im::login::IMLoginService
// Notice that implementing brpc::Describable grants the ability to put
// additional information in /status.
namespace antalk {
namespace auth {

class LoginServiceImpl : public LoginService {
public:
    LoginServiceImpl() {};
    virtual ~LoginServiceImpl() {};
	virtual void Login(google::protobuf::RpcController* cntl_base,
		               const LoginReq* request,
		               LoginResp* response,
		               google::protobuf::Closure* done);

private:
    antalk::common::ResultType CheckParam(const LoginReq& req);
    antalk::common::ResultType CheckAuthFromDataSvr(const LoginReq& req);
};

}  // namespace example
}

#endif
