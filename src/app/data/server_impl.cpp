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
//#include "acl_cpp/lib_acl.hpp"

namespace antalk {
namespace data {

void UserStatusServiceImpl::GetUserInfo(google::protobuf::RpcController* cntl_base,
    const GetUserInfoReq* request,
    GetUserInfoRes* response,
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
        << ": " << request->uid()
        << " (attached=" << cntl->request_attachment() << ")";

    antalk::common::UserInfo user_info;
    user_info.set_passwd("123456");
    //DataManager::Instance().GetUserInfo(request->saas_id(), request->user_id(), user_info);
    response->set_allocated_user_info(&user_info);

    // Fill response.
    //response->set_result_code(im::base::REFUSE_REASON_NONE);


    //acl::acl_cpp_init();
    //acl::string dbaddr("127.0.0.1:3306");
    //acl::string dbname("antalk"), dbuser("root"), dbpass("123456");
    //acl::db_mysql db(dbaddr, dbname, dbuser, dbpass, 0, false);
    //int   max = 100;

    //// 先打开数据库连接
    //if (db.open() == false)
    //{

    //}

    //acl::query query;
    //query.create_sql("select * from group_tbl where group_name=:group"
    //    " and uvip_tbl=:test")
    //    .set_format("group", "group:%d", 1)
    //    .set_format("test", "test");

    //if (db.exec_select(query) == false)
    //{
    //    printf("select sql error\r\n");
    //}

    //// 列出查询结果方法一
    //const acl::db_rows* result = db.get_result();
    //if (result)
    //{
    //    const std::vector<acl::db_row*>& rows = result->get_rows();
    //    for (size_t i = 0; i < rows.size(); i++)
    //    {
    //        //if (n > 100)
    //        //    continue;
    //        const acl::db_row* row = rows[i];
    //        for (size_t j = 0; j < row->length(); j++)
    //            printf("%s, ", (*row)[j]);
    //        printf("\r\n");
    //    }
    //}
}

}
}
