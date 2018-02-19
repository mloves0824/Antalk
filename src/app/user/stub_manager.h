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
#ifndef SRC_APP_USER_STUB_MANAGER_H_
#define SRC_APP_USER_STUB_MANAGER_H_

#include <brpc/channel.h>
#include "data.user.pb.h"
#include "server_config.h"

namespace antalk {
namespace user {

class StubManager {
public:
	static StubManager& Instance();
	bool Init();

	data::user::GetUserInfoService_Stub* GetStub() {
		return getuserinfo_stub_;
	}

private:
	StubManager() : getuserinfo_stub_(NULL) {}
	~StubManager() {
		if (getuserinfo_stub_) free(getuserinfo_stub_);
	}

private:
	data::user::GetUserInfoService_Stub* getuserinfo_stub_;

};

}
}



#endif /* SRC_APP_USER_STUB_MANAGER_H_ */
