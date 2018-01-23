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

#ifndef DB_POOL_MGR_H
#define DB_POOL_MGR_H

#include <stdlib.h>
#include "db_handle_mgr.h"

namespace anrpc {
namespace db {
	
class DbPoolMgr {

	/**
	* 数据库连接管理构造函数
	* @param addr {const char*} 数据库地址
	* @param count {size_t} 连接池最大连接个数限制
	* @param idx {size_t} 该连接池对象在集合中的下标位置(从 0 开始)
	*/
	DbPoolMgr(const char* addr, size_t count, size_t idx = 0);
	virtual ~DbPoolMgr() {};

	/**
	* 从数据库连接池获得一个数据库对象，并且要求打开数据库连接，即用户不必
	* 显式地再调用 db_handle::open 过程；
	* 用完后必须调用 db_pool->put(db_handle*) 将连接归还至数据库连接池，
	* 由该函数获得的连接句柄不能 delete，否则会造成连接池的内部计数器出错
	* @param charset {const char*} 打开数据库时采用的字符集
	* @return {db_handle*} 数据库连接对象，返回空表示出错
	*/
	DbHandle* peek_open(const char* charset = NULL);
};
	
}
}

#endif