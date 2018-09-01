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

#include "server_impl.h"

namespace antalk {
namespace apigw {

void LoginServiceImpl::Login(google::protobuf::RpcController* cntl_base,
    const LoginReq* request,
    LoginResp* response,
    google::protobuf::Closure* done) {
    // This object helps you to call done->Run() in RAII style. If you need
    // to process the request asynchronously, pass done_guard.release().
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    // The purpose of following logs is to help you to understand
    // how clients interact with servers more intuitively. You should 
    // remove these logs in performance-sensitive servers.
    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
        << "] from " << cntl->remote_side()
        << " to " << cntl->local_side()
        //<< ": " << request->message()
        << " (attached=" << cntl->request_attachment() << ")";

    // Fill response.
    response->set_result_code(antalk::common::REFUSE_REASON_NONE);

    // You can compress the response by setting Controller, but be aware
    // that compression may be costly, evaluate before turning on.
    // cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);

    //if (FLAGS_echo_attachment) {
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    //cntl->response_attachment().append(cntl->request_attachment());
    //}
}

//antalk::common::ResultType LoginServiceImpl::CheckParam(const LoginReq &req) {
//}


antalk::common::ResultType LoginServiceImpl::CheckAuth(const LoginReq &req) {

	//1. create channel
    // A Channel represents a communication line to a Server. Notice that
    // Channel is thread-safe and can be shared by all threads in your program.
    brpc::Channel channel;
    // Initialize the channel, NULL means using default options.
    brpc::ChannelOptions options;
    options.protocol = brpc::PROTOCOL_BAIDU_STD;
    options.connection_type = brpc::CONNECTION_TYPE_SHORT;
    options.timeout_ms = 100/*milliseconds*/;
    options.max_retry = 3;
    if (channel.Init("127.0.0.1:8002", &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return antalk::common::ERROR_CONNECT_TO_AUTH;
    }

    //2. build request
    antalk::auth::LoginReq auth_login_req;
    auth_login_req.set_uid(req.uid());
    auth_login_req.set_password(req.password());
    antalk::auth::LoginResp auth_login_resp;

    //3. send request
    // Normally, you should not call a Channel directly, but instead construct
    // a stub Service wrapping it. stub can be shared by all threads as well.
    antalk::auth::LoginService_Stub stub(&channel);
    brpc::Controller cntl;
    stub.Login(&cntl, &auth_login_req, &auth_login_resp, NULL);
    if (cntl.Failed()) {
        // RPC失败了. response里的值是未定义的，勿用。
        LOG(ERROR) << "Fail to send rpc request";
        return antalk::common::ERROR_RPC_TO_AUTH;
    } else {
        // RPC成功了，response里有我们想要的回复数据。
    }

    return antalk::common::REFUSE_REASON_NONE;
}

}
}
