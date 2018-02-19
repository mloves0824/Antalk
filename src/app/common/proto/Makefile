PROTOC = protoc
PROTOC_EXTRA_ARGS = 

.PHONY:all
all: im.base.pb.cc  user.login.pb.cc data.user.pb.cc 

.PHONY:clean
clean:
	@echo "Cleaning"
	@rm -rf %.pb.cc %.pb.h



%.pb.cc %.pb.h:%.proto
	@echo "Generating $@"
	@$(PROTOC) --cpp_out=. --proto_path=. $(PROTOC_EXTRA_ARGS) $<

libproto.so:%.o

%.o:%.cpp
	@echo "Compiling $@"
	@$(CXX) -c $(HDRPATHS) $(CXXFLAGS) $< -o $@

%.o:%.cc
	@echo "Compiling $@"
	@$(CXX) -c $(HDRPATHS) $(CXXFLAGS) $< -o $@
