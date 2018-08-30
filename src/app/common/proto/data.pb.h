// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: data.proto

#ifndef PROTOBUF_data_2eproto__INCLUDED
#define PROTOBUF_data_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_data_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsGetUserInfoReqImpl();
void InitDefaultsGetUserInfoReq();
void InitDefaultsGetUserInfoResImpl();
void InitDefaultsGetUserInfoRes();
void InitDefaultsSetUserStatusReqImpl();
void InitDefaultsSetUserStatusReq();
void InitDefaultsSetUserStatusRespImpl();
void InitDefaultsSetUserStatusResp();
inline void InitDefaults() {
  InitDefaultsGetUserInfoReq();
  InitDefaultsGetUserInfoRes();
  InitDefaultsSetUserStatusReq();
  InitDefaultsSetUserStatusResp();
}
}  // namespace protobuf_data_2eproto
namespace antalk {
namespace data {
class GetUserInfoReq;
class GetUserInfoReqDefaultTypeInternal;
extern GetUserInfoReqDefaultTypeInternal _GetUserInfoReq_default_instance_;
class GetUserInfoRes;
class GetUserInfoResDefaultTypeInternal;
extern GetUserInfoResDefaultTypeInternal _GetUserInfoRes_default_instance_;
class SetUserStatusReq;
class SetUserStatusReqDefaultTypeInternal;
extern SetUserStatusReqDefaultTypeInternal _SetUserStatusReq_default_instance_;
class SetUserStatusResp;
class SetUserStatusRespDefaultTypeInternal;
extern SetUserStatusRespDefaultTypeInternal _SetUserStatusResp_default_instance_;
}  // namespace data
}  // namespace antalk
namespace antalk {
namespace data {

// ===================================================================

class GetUserInfoReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:antalk.data.GetUserInfoReq) */ {
 public:
  GetUserInfoReq();
  virtual ~GetUserInfoReq();

  GetUserInfoReq(const GetUserInfoReq& from);

  inline GetUserInfoReq& operator=(const GetUserInfoReq& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetUserInfoReq(GetUserInfoReq&& from) noexcept
    : GetUserInfoReq() {
    *this = ::std::move(from);
  }

  inline GetUserInfoReq& operator=(GetUserInfoReq&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetUserInfoReq& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetUserInfoReq* internal_default_instance() {
    return reinterpret_cast<const GetUserInfoReq*>(
               &_GetUserInfoReq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(GetUserInfoReq* other);
  friend void swap(GetUserInfoReq& a, GetUserInfoReq& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetUserInfoReq* New() const PROTOBUF_FINAL { return New(NULL); }

  GetUserInfoReq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GetUserInfoReq& from);
  void MergeFrom(const GetUserInfoReq& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GetUserInfoReq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 saas_id = 1;
  bool has_saas_id() const;
  void clear_saas_id();
  static const int kSaasIdFieldNumber = 1;
  ::google::protobuf::uint32 saas_id() const;
  void set_saas_id(::google::protobuf::uint32 value);

  // required uint32 user_id = 2;
  bool has_user_id() const;
  void clear_user_id();
  static const int kUserIdFieldNumber = 2;
  ::google::protobuf::uint32 user_id() const;
  void set_user_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:antalk.data.GetUserInfoReq)
 private:
  void set_has_saas_id();
  void clear_has_saas_id();
  void set_has_user_id();
  void clear_has_user_id();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 saas_id_;
  ::google::protobuf::uint32 user_id_;
  friend struct ::protobuf_data_2eproto::TableStruct;
  friend void ::protobuf_data_2eproto::InitDefaultsGetUserInfoReqImpl();
};
// -------------------------------------------------------------------

class GetUserInfoRes : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:antalk.data.GetUserInfoRes) */ {
 public:
  GetUserInfoRes();
  virtual ~GetUserInfoRes();

  GetUserInfoRes(const GetUserInfoRes& from);

  inline GetUserInfoRes& operator=(const GetUserInfoRes& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetUserInfoRes(GetUserInfoRes&& from) noexcept
    : GetUserInfoRes() {
    *this = ::std::move(from);
  }

  inline GetUserInfoRes& operator=(GetUserInfoRes&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetUserInfoRes& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetUserInfoRes* internal_default_instance() {
    return reinterpret_cast<const GetUserInfoRes*>(
               &_GetUserInfoRes_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(GetUserInfoRes* other);
  friend void swap(GetUserInfoRes& a, GetUserInfoRes& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetUserInfoRes* New() const PROTOBUF_FINAL { return New(NULL); }

  GetUserInfoRes* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GetUserInfoRes& from);
  void MergeFrom(const GetUserInfoRes& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GetUserInfoRes* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .antalk.common.UserInfo user_info = 1;
  bool has_user_info() const;
  void clear_user_info();
  static const int kUserInfoFieldNumber = 1;
  const ::antalk::common::UserInfo& user_info() const;
  ::antalk::common::UserInfo* release_user_info();
  ::antalk::common::UserInfo* mutable_user_info();
  void set_allocated_user_info(::antalk::common::UserInfo* user_info);

  // @@protoc_insertion_point(class_scope:antalk.data.GetUserInfoRes)
 private:
  void set_has_user_info();
  void clear_has_user_info();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::antalk::common::UserInfo* user_info_;
  friend struct ::protobuf_data_2eproto::TableStruct;
  friend void ::protobuf_data_2eproto::InitDefaultsGetUserInfoResImpl();
};
// -------------------------------------------------------------------

class SetUserStatusReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:antalk.data.SetUserStatusReq) */ {
 public:
  SetUserStatusReq();
  virtual ~SetUserStatusReq();

  SetUserStatusReq(const SetUserStatusReq& from);

  inline SetUserStatusReq& operator=(const SetUserStatusReq& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SetUserStatusReq(SetUserStatusReq&& from) noexcept
    : SetUserStatusReq() {
    *this = ::std::move(from);
  }

  inline SetUserStatusReq& operator=(SetUserStatusReq&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SetUserStatusReq& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SetUserStatusReq* internal_default_instance() {
    return reinterpret_cast<const SetUserStatusReq*>(
               &_SetUserStatusReq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(SetUserStatusReq* other);
  friend void swap(SetUserStatusReq& a, SetUserStatusReq& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SetUserStatusReq* New() const PROTOBUF_FINAL { return New(NULL); }

  SetUserStatusReq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SetUserStatusReq& from);
  void MergeFrom(const SetUserStatusReq& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SetUserStatusReq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string uid = 1;
  bool has_uid() const;
  void clear_uid();
  static const int kUidFieldNumber = 1;
  const ::std::string& uid() const;
  void set_uid(const ::std::string& value);
  #if LANG_CXX11
  void set_uid(::std::string&& value);
  #endif
  void set_uid(const char* value);
  void set_uid(const char* value, size_t size);
  ::std::string* mutable_uid();
  ::std::string* release_uid();
  void set_allocated_uid(::std::string* uid);

  // optional string session = 3;
  bool has_session() const;
  void clear_session();
  static const int kSessionFieldNumber = 3;
  const ::std::string& session() const;
  void set_session(const ::std::string& value);
  #if LANG_CXX11
  void set_session(::std::string&& value);
  #endif
  void set_session(const char* value);
  void set_session(const char* value, size_t size);
  ::std::string* mutable_session();
  ::std::string* release_session();
  void set_allocated_session(::std::string* session);

  // optional string login_info = 5;
  bool has_login_info() const;
  void clear_login_info();
  static const int kLoginInfoFieldNumber = 5;
  const ::std::string& login_info() const;
  void set_login_info(const ::std::string& value);
  #if LANG_CXX11
  void set_login_info(::std::string&& value);
  #endif
  void set_login_info(const char* value);
  void set_login_info(const char* value, size_t size);
  ::std::string* mutable_login_info();
  ::std::string* release_login_info();
  void set_allocated_login_info(::std::string* login_info);

  // optional int32 dev_type = 2;
  bool has_dev_type() const;
  void clear_dev_type();
  static const int kDevTypeFieldNumber = 2;
  ::google::protobuf::int32 dev_type() const;
  void set_dev_type(::google::protobuf::int32 value);

  // optional int32 status = 4;
  bool has_status() const;
  void clear_status();
  static const int kStatusFieldNumber = 4;
  ::google::protobuf::int32 status() const;
  void set_status(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:antalk.data.SetUserStatusReq)
 private:
  void set_has_uid();
  void clear_has_uid();
  void set_has_dev_type();
  void clear_has_dev_type();
  void set_has_session();
  void clear_has_session();
  void set_has_status();
  void clear_has_status();
  void set_has_login_info();
  void clear_has_login_info();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr uid_;
  ::google::protobuf::internal::ArenaStringPtr session_;
  ::google::protobuf::internal::ArenaStringPtr login_info_;
  ::google::protobuf::int32 dev_type_;
  ::google::protobuf::int32 status_;
  friend struct ::protobuf_data_2eproto::TableStruct;
  friend void ::protobuf_data_2eproto::InitDefaultsSetUserStatusReqImpl();
};
// -------------------------------------------------------------------

class SetUserStatusResp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:antalk.data.SetUserStatusResp) */ {
 public:
  SetUserStatusResp();
  virtual ~SetUserStatusResp();

  SetUserStatusResp(const SetUserStatusResp& from);

  inline SetUserStatusResp& operator=(const SetUserStatusResp& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SetUserStatusResp(SetUserStatusResp&& from) noexcept
    : SetUserStatusResp() {
    *this = ::std::move(from);
  }

  inline SetUserStatusResp& operator=(SetUserStatusResp&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SetUserStatusResp& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SetUserStatusResp* internal_default_instance() {
    return reinterpret_cast<const SetUserStatusResp*>(
               &_SetUserStatusResp_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(SetUserStatusResp* other);
  friend void swap(SetUserStatusResp& a, SetUserStatusResp& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SetUserStatusResp* New() const PROTOBUF_FINAL { return New(NULL); }

  SetUserStatusResp* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SetUserStatusResp& from);
  void MergeFrom(const SetUserStatusResp& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SetUserStatusResp* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .antalk.common.ResultType result = 1;
  bool has_result() const;
  void clear_result();
  static const int kResultFieldNumber = 1;
  ::antalk::common::ResultType result() const;
  void set_result(::antalk::common::ResultType value);

  // @@protoc_insertion_point(class_scope:antalk.data.SetUserStatusResp)
 private:
  void set_has_result();
  void clear_has_result();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  int result_;
  friend struct ::protobuf_data_2eproto::TableStruct;
  friend void ::protobuf_data_2eproto::InitDefaultsSetUserStatusRespImpl();
};
// ===================================================================

class GetUserInfoService_Stub;

class GetUserInfoService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline GetUserInfoService() {};
 public:
  virtual ~GetUserInfoService();

  typedef GetUserInfoService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void GetUserInfo(::google::protobuf::RpcController* controller,
                       const ::antalk::data::GetUserInfoReq* request,
                       ::antalk::data::GetUserInfoRes* response,
                       ::google::protobuf::Closure* done);
  virtual void SetUserStatus(::google::protobuf::RpcController* controller,
                       const ::antalk::data::SetUserStatusReq* request,
                       ::antalk::data::SetUserStatusResp* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(GetUserInfoService);
};

class GetUserInfoService_Stub : public GetUserInfoService {
 public:
  GetUserInfoService_Stub(::google::protobuf::RpcChannel* channel);
  GetUserInfoService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~GetUserInfoService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements GetUserInfoService ------------------------------------------

  void GetUserInfo(::google::protobuf::RpcController* controller,
                       const ::antalk::data::GetUserInfoReq* request,
                       ::antalk::data::GetUserInfoRes* response,
                       ::google::protobuf::Closure* done);
  void SetUserStatus(::google::protobuf::RpcController* controller,
                       const ::antalk::data::SetUserStatusReq* request,
                       ::antalk::data::SetUserStatusResp* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(GetUserInfoService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetUserInfoReq

// required uint32 saas_id = 1;
inline bool GetUserInfoReq::has_saas_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetUserInfoReq::set_has_saas_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetUserInfoReq::clear_has_saas_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetUserInfoReq::clear_saas_id() {
  saas_id_ = 0u;
  clear_has_saas_id();
}
inline ::google::protobuf::uint32 GetUserInfoReq::saas_id() const {
  // @@protoc_insertion_point(field_get:antalk.data.GetUserInfoReq.saas_id)
  return saas_id_;
}
inline void GetUserInfoReq::set_saas_id(::google::protobuf::uint32 value) {
  set_has_saas_id();
  saas_id_ = value;
  // @@protoc_insertion_point(field_set:antalk.data.GetUserInfoReq.saas_id)
}

// required uint32 user_id = 2;
inline bool GetUserInfoReq::has_user_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetUserInfoReq::set_has_user_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetUserInfoReq::clear_has_user_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetUserInfoReq::clear_user_id() {
  user_id_ = 0u;
  clear_has_user_id();
}
inline ::google::protobuf::uint32 GetUserInfoReq::user_id() const {
  // @@protoc_insertion_point(field_get:antalk.data.GetUserInfoReq.user_id)
  return user_id_;
}
inline void GetUserInfoReq::set_user_id(::google::protobuf::uint32 value) {
  set_has_user_id();
  user_id_ = value;
  // @@protoc_insertion_point(field_set:antalk.data.GetUserInfoReq.user_id)
}

// -------------------------------------------------------------------

// GetUserInfoRes

// required .antalk.common.UserInfo user_info = 1;
inline bool GetUserInfoRes::has_user_info() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetUserInfoRes::set_has_user_info() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetUserInfoRes::clear_has_user_info() {
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::antalk::common::UserInfo& GetUserInfoRes::user_info() const {
  const ::antalk::common::UserInfo* p = user_info_;
  // @@protoc_insertion_point(field_get:antalk.data.GetUserInfoRes.user_info)
  return p != NULL ? *p : *reinterpret_cast<const ::antalk::common::UserInfo*>(
      &::antalk::common::_UserInfo_default_instance_);
}
inline ::antalk::common::UserInfo* GetUserInfoRes::release_user_info() {
  // @@protoc_insertion_point(field_release:antalk.data.GetUserInfoRes.user_info)
  clear_has_user_info();
  ::antalk::common::UserInfo* temp = user_info_;
  user_info_ = NULL;
  return temp;
}
inline ::antalk::common::UserInfo* GetUserInfoRes::mutable_user_info() {
  set_has_user_info();
  if (user_info_ == NULL) {
    user_info_ = new ::antalk::common::UserInfo;
  }
  // @@protoc_insertion_point(field_mutable:antalk.data.GetUserInfoRes.user_info)
  return user_info_;
}
inline void GetUserInfoRes::set_allocated_user_info(::antalk::common::UserInfo* user_info) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(user_info_);
  }
  if (user_info) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      user_info = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, user_info, submessage_arena);
    }
    set_has_user_info();
  } else {
    clear_has_user_info();
  }
  user_info_ = user_info;
  // @@protoc_insertion_point(field_set_allocated:antalk.data.GetUserInfoRes.user_info)
}

// -------------------------------------------------------------------

// SetUserStatusReq

// optional string uid = 1;
inline bool SetUserStatusReq::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SetUserStatusReq::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SetUserStatusReq::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SetUserStatusReq::clear_uid() {
  uid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_uid();
}
inline const ::std::string& SetUserStatusReq::uid() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusReq.uid)
  return uid_.GetNoArena();
}
inline void SetUserStatusReq::set_uid(const ::std::string& value) {
  set_has_uid();
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusReq.uid)
}
#if LANG_CXX11
inline void SetUserStatusReq::set_uid(::std::string&& value) {
  set_has_uid();
  uid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:antalk.data.SetUserStatusReq.uid)
}
#endif
inline void SetUserStatusReq::set_uid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_uid();
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:antalk.data.SetUserStatusReq.uid)
}
inline void SetUserStatusReq::set_uid(const char* value, size_t size) {
  set_has_uid();
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:antalk.data.SetUserStatusReq.uid)
}
inline ::std::string* SetUserStatusReq::mutable_uid() {
  set_has_uid();
  // @@protoc_insertion_point(field_mutable:antalk.data.SetUserStatusReq.uid)
  return uid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SetUserStatusReq::release_uid() {
  // @@protoc_insertion_point(field_release:antalk.data.SetUserStatusReq.uid)
  clear_has_uid();
  return uid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SetUserStatusReq::set_allocated_uid(::std::string* uid) {
  if (uid != NULL) {
    set_has_uid();
  } else {
    clear_has_uid();
  }
  uid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uid);
  // @@protoc_insertion_point(field_set_allocated:antalk.data.SetUserStatusReq.uid)
}

// optional int32 dev_type = 2;
inline bool SetUserStatusReq::has_dev_type() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SetUserStatusReq::set_has_dev_type() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SetUserStatusReq::clear_has_dev_type() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SetUserStatusReq::clear_dev_type() {
  dev_type_ = 0;
  clear_has_dev_type();
}
inline ::google::protobuf::int32 SetUserStatusReq::dev_type() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusReq.dev_type)
  return dev_type_;
}
inline void SetUserStatusReq::set_dev_type(::google::protobuf::int32 value) {
  set_has_dev_type();
  dev_type_ = value;
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusReq.dev_type)
}

// optional string session = 3;
inline bool SetUserStatusReq::has_session() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SetUserStatusReq::set_has_session() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SetUserStatusReq::clear_has_session() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SetUserStatusReq::clear_session() {
  session_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_session();
}
inline const ::std::string& SetUserStatusReq::session() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusReq.session)
  return session_.GetNoArena();
}
inline void SetUserStatusReq::set_session(const ::std::string& value) {
  set_has_session();
  session_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusReq.session)
}
#if LANG_CXX11
inline void SetUserStatusReq::set_session(::std::string&& value) {
  set_has_session();
  session_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:antalk.data.SetUserStatusReq.session)
}
#endif
inline void SetUserStatusReq::set_session(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_session();
  session_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:antalk.data.SetUserStatusReq.session)
}
inline void SetUserStatusReq::set_session(const char* value, size_t size) {
  set_has_session();
  session_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:antalk.data.SetUserStatusReq.session)
}
inline ::std::string* SetUserStatusReq::mutable_session() {
  set_has_session();
  // @@protoc_insertion_point(field_mutable:antalk.data.SetUserStatusReq.session)
  return session_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SetUserStatusReq::release_session() {
  // @@protoc_insertion_point(field_release:antalk.data.SetUserStatusReq.session)
  clear_has_session();
  return session_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SetUserStatusReq::set_allocated_session(::std::string* session) {
  if (session != NULL) {
    set_has_session();
  } else {
    clear_has_session();
  }
  session_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), session);
  // @@protoc_insertion_point(field_set_allocated:antalk.data.SetUserStatusReq.session)
}

// optional int32 status = 4;
inline bool SetUserStatusReq::has_status() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SetUserStatusReq::set_has_status() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SetUserStatusReq::clear_has_status() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SetUserStatusReq::clear_status() {
  status_ = 0;
  clear_has_status();
}
inline ::google::protobuf::int32 SetUserStatusReq::status() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusReq.status)
  return status_;
}
inline void SetUserStatusReq::set_status(::google::protobuf::int32 value) {
  set_has_status();
  status_ = value;
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusReq.status)
}

// optional string login_info = 5;
inline bool SetUserStatusReq::has_login_info() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SetUserStatusReq::set_has_login_info() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SetUserStatusReq::clear_has_login_info() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SetUserStatusReq::clear_login_info() {
  login_info_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_login_info();
}
inline const ::std::string& SetUserStatusReq::login_info() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusReq.login_info)
  return login_info_.GetNoArena();
}
inline void SetUserStatusReq::set_login_info(const ::std::string& value) {
  set_has_login_info();
  login_info_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusReq.login_info)
}
#if LANG_CXX11
inline void SetUserStatusReq::set_login_info(::std::string&& value) {
  set_has_login_info();
  login_info_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:antalk.data.SetUserStatusReq.login_info)
}
#endif
inline void SetUserStatusReq::set_login_info(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_login_info();
  login_info_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:antalk.data.SetUserStatusReq.login_info)
}
inline void SetUserStatusReq::set_login_info(const char* value, size_t size) {
  set_has_login_info();
  login_info_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:antalk.data.SetUserStatusReq.login_info)
}
inline ::std::string* SetUserStatusReq::mutable_login_info() {
  set_has_login_info();
  // @@protoc_insertion_point(field_mutable:antalk.data.SetUserStatusReq.login_info)
  return login_info_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SetUserStatusReq::release_login_info() {
  // @@protoc_insertion_point(field_release:antalk.data.SetUserStatusReq.login_info)
  clear_has_login_info();
  return login_info_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SetUserStatusReq::set_allocated_login_info(::std::string* login_info) {
  if (login_info != NULL) {
    set_has_login_info();
  } else {
    clear_has_login_info();
  }
  login_info_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), login_info);
  // @@protoc_insertion_point(field_set_allocated:antalk.data.SetUserStatusReq.login_info)
}

// -------------------------------------------------------------------

// SetUserStatusResp

// optional .antalk.common.ResultType result = 1;
inline bool SetUserStatusResp::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SetUserStatusResp::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SetUserStatusResp::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SetUserStatusResp::clear_result() {
  result_ = 0;
  clear_has_result();
}
inline ::antalk::common::ResultType SetUserStatusResp::result() const {
  // @@protoc_insertion_point(field_get:antalk.data.SetUserStatusResp.result)
  return static_cast< ::antalk::common::ResultType >(result_);
}
inline void SetUserStatusResp::set_result(::antalk::common::ResultType value) {
  assert(::antalk::common::ResultType_IsValid(value));
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:antalk.data.SetUserStatusResp.result)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace data
}  // namespace antalk

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_data_2eproto__INCLUDED
