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

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>
#include "apigw.pb.h"

DEFINE_string(attachment, "foo", "Carry this along with requests");
DEFINE_string(protocol, "baidu_std", "Protocol type. Defined in src/brpc/options.proto");
DEFINE_string(connection_type, "", "Connection type. Available values: single, pooled, short");
DEFINE_string(server, "0.0.0.0:8000", "IP Address of server");
DEFINE_string(load_balancer, "", "The algorithm for load balancing");
DEFINE_int32(timeout_ms, 100, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)");
DEFINE_int32(interval_ms, 1000, "Milliseconds between consecutive requests");
DEFINE_string(http_content_type, "application/json", "Content type of http request");

int main(int argc, char* argv[]) {
	// Parse gflags. We recommend you to use gflags as well.
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	// A Channel represents a communication line to a Server. Notice that 
	// Channel is thread-safe and can be shared by all threads in your program.
	brpc::Channel channel;

	// Initialize the channel, NULL means using default options.
	brpc::ChannelOptions options;
	options.protocol = FLAGS_protocol;
	options.connection_type = FLAGS_connection_type;
	options.timeout_ms = FLAGS_timeout_ms/*milliseconds*/;
	options.max_retry = FLAGS_max_retry;
	if (channel.Init(FLAGS_server.c_str(), FLAGS_load_balancer.c_str(), &options) != 0) {
		LOG(ERROR) << "Fail to initialize channel";
		return -1;
	}

	// Normally, you should not call a Channel directly, but instead construct
	// a stub Service wrapping it. stub can be shared by all threads as well.
    antalk::apigw::LoginService_Stub stub(&channel);

    // We will receive response synchronously, safe to put variables
    // on stack.
    antalk::apigw::LoginReq request;
    antalk::apigw::LoginResp response;

    brpc::Controller cntl;

    request.set_uid("test");
    request.set_password("123456");

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.Login(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            //	<< ": " << response.message() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
		if (antalk::common::REFUSE_REASON_NONE == response.result_code()) {
			LOG(INFO) << "Login success!";
		} else {
			LOG(INFO) << "Login failed!";
		}
    }
    else {
        LOG(WARNING) << cntl.ErrorText();
    }
    usleep(FLAGS_interval_ms * 1000L);

	LOG(INFO) << "EchoClient is going to quit";
	return 0;
}

