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
#ifndef SRC_APP_DATA_DATA_MANAGER_H_
#define SRC_APP_DATA_DATA_MANAGER_H_

#include "im.base.pb.h"
#include "data.user.pb.h"

namespace antalk {
namespace data {

class DataManager {
public:
	static DataManager& Instance();
	im::base::UserInfo& GetUserInfo(const antalk::data::user::GetUserInfoReq *req);

private:
	DataManager();
	~DataManager();

};

}
}



#endif /* SRC_APP_DATA_DATA_MANAGER_H_ */
