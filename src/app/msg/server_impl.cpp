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
namespace msg {

void MsgServiceImpl::SendMsg(google::protobuf::RpcController* cntl_base,
    const SendMsgReq* request,
    SendMsgResp* response,
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

    // You can compress the response by setting Controller, but be aware
    // that compression may be costly, evaluate before turning on.
    // cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);

    //if (FLAGS_echo_attachment) {
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    //cntl->response_attachment().append(cntl->request_attachment());
    //}
}


antalk::common::ResultType MsgServiceImpl::SaveMsg(const antalk::common::MsgInfo& msg_info) {
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
    if (channel.Init("127.0.0.1:18002", &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return antalk::common::ERROR_CONNECT_TO_AUTH;
    }

    //2. build request
    antalk::data::SaveMsgReq data_savemsg_req;
    antalk::data::SaveMsgResp data_savemsg_resp;
    data_savemsg_req.mutable_msg_info()->CopyFrom(msg_info);


    //3. send request
    // Normally, you should not call a Channel directly, but instead construct
    // a stub Service wrapping it. stub can be shared by all threads as well.
    antalk::data::MsgService_Stub stub(&channel);
    brpc::Controller cntl;
    stub.SaveMsg(&cntl, &data_savemsg_req, &data_savemsg_resp, NULL);
    if (cntl.Failed()) {
        // RPC失败了. response里的值是未定义的，勿用。
        LOG(ERROR) << "Fail to send rpc request:" << cntl.ErrorText();
        return antalk::common::ERROR_RPC_TO_AUTH;
    }
    else {
        // RPC成功了，response里有我们想要的回复数据。
        return antalk::common::REFUSE_REASON_NONE;
    }
}


antalk::common::ResultType MsgServiceImpl::NotifyMsg(const antalk::common::MsgInfo& msg_info) {
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
    if (channel.Init("127.0.0.1:18000", &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return antalk::common::ERROR_CONNECT_TO_AUTH;
    }

    //2. build request
    antalk::apigw::NotifyMsgReq apigw_notifymsg_req;
    antalk::apigw::NotifyMsgResp apigw_notifymsg_resp;
    apigw_notifymsg_req.mutable_msg_info()->CopyFrom(msg_info);


    //3. send request
    // Normally, you should not call a Channel directly, but instead construct
    // a stub Service wrapping it. stub can be shared by all threads as well.
    antalk::apigw::MsgService_Stub stub(&channel);
    brpc::Controller cntl;
    stub.NotifyMsg(&cntl, &apigw_notifymsg_req, &apigw_notifymsg_resp, NULL);
    if (cntl.Failed()) {
        // RPC失败了. response里的值是未定义的，勿用。
        LOG(ERROR) << "Fail to send rpc request:" << cntl.ErrorText();
        return antalk::common::ERROR_RPC_TO_AUTH;
    }
    else {
        // RPC成功了，response里有我们想要的回复数据。
        return antalk::common::REFUSE_REASON_NONE;
    }
}

}
}
