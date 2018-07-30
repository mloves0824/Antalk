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

#include "phxqueue/consumer.h"
#include "queue_handle_mgr.h"

using namespace phxqueue;

namespace anrpc {
namespace queue {

class PhxQueueHandleMgr : public consumer::Consumer, public QueueHandleMgr {
public:
    PhxQueueHandleMgr(const consumer::ConsumerOption &opt) : consumer::Consumer(opt) {}
    virtual ~PhxQueueHandleMgr() override = default;

    virtual comm::RetCode Get(const comm::proto::GetRequest &req,
        comm::proto::GetResponse &resp) override;
    virtual comm::RetCode Add(const comm::proto::AddRequest &req,
        comm::proto::AddResponse &resp) override;

    virtual comm::RetCode UncompressBuffer(const std::string &buffer,
        const int buffer_type,
        std::string &decoded_buffer) override;
    virtual void RestoreUserCookies(const comm::proto::Cookies &user_cookies) override;
    virtual void CompressBuffer(const std::string &buffer, std::string &compress_buffer,
        const int buffer_type) override;
    virtual comm::RetCode GetAddrScale(const comm::proto::GetAddrScaleRequest &req,
        comm::proto::GetAddrScaleResponse &resp) override;
    virtual comm::RetCode GetQueueByAddrScale(const std::vector<consumer::Queue_t> &queues,
        const consumer::AddrScales &addr_scales,
        std::set<size_t> &queue_idxs) override;
    virtual comm::RetCode GetLockInfo(const comm::proto::GetLockInfoRequest &req,
        comm::proto::GetLockInfoResponse &resp) override;
    virtual comm::RetCode AcquireLock(const comm::proto::AcquireLockRequest &req,
        comm::proto::AcquireLockResponse &resp) override;

    virtual void BeforeLock(const comm::proto::ConsumerContext &cc) override;
    virtual void AfterLock(const comm::proto::ConsumerContext &cc) override;
};

}//namespace anrpc
} //namespace anrpc