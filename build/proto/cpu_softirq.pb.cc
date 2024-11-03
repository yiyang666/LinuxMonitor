// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cpu_softirq.proto

#include "cpu_softirq.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace monitor {
namespace proto {
class SoftIrqDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SoftIrq> _instance;
} _SoftIrq_default_instance_;
}  // namespace proto
}  // namespace monitor
static void InitDefaultsscc_info_SoftIrq_cpu_5fsoftirq_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::monitor::proto::_SoftIrq_default_instance_;
    new (ptr) ::monitor::proto::SoftIrq();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SoftIrq_cpu_5fsoftirq_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SoftIrq_cpu_5fsoftirq_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cpu_5fsoftirq_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cpu_5fsoftirq_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cpu_5fsoftirq_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cpu_5fsoftirq_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, cpu_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, hi_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, timer_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, net_tx_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, net_rx_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, block_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, irq_poll_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, tasklet_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, sched_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, hrtimer_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::SoftIrq, rcu_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::monitor::proto::SoftIrq)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::monitor::proto::_SoftIrq_default_instance_),
};

const char descriptor_table_protodef_cpu_5fsoftirq_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021cpu_softirq.proto\022\rmonitor.proto\"\260\001\n\007S"
  "oftIrq\022\013\n\003cpu\030\001 \001(\t\022\n\n\002hi\030\002 \001(\002\022\r\n\005timer"
  "\030\003 \001(\002\022\016\n\006net_tx\030\004 \001(\002\022\016\n\006net_rx\030\005 \001(\002\022\r"
  "\n\005block\030\006 \001(\002\022\020\n\010irq_poll\030\007 \001(\002\022\017\n\007taskl"
  "et\030\010 \001(\002\022\r\n\005sched\030\t \001(\002\022\017\n\007hrtimer\030\n \001(\002"
  "\022\013\n\003rcu\030\013 \001(\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cpu_5fsoftirq_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cpu_5fsoftirq_2eproto_sccs[1] = {
  &scc_info_SoftIrq_cpu_5fsoftirq_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cpu_5fsoftirq_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cpu_5fsoftirq_2eproto = {
  false, false, descriptor_table_protodef_cpu_5fsoftirq_2eproto, "cpu_softirq.proto", 221,
  &descriptor_table_cpu_5fsoftirq_2eproto_once, descriptor_table_cpu_5fsoftirq_2eproto_sccs, descriptor_table_cpu_5fsoftirq_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_cpu_5fsoftirq_2eproto::offsets,
  file_level_metadata_cpu_5fsoftirq_2eproto, 1, file_level_enum_descriptors_cpu_5fsoftirq_2eproto, file_level_service_descriptors_cpu_5fsoftirq_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cpu_5fsoftirq_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cpu_5fsoftirq_2eproto)), true);
namespace monitor {
namespace proto {

// ===================================================================

class SoftIrq::_Internal {
 public:
};

SoftIrq::SoftIrq(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:monitor.proto.SoftIrq)
}
SoftIrq::SoftIrq(const SoftIrq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  cpu_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_cpu().empty()) {
    cpu_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_cpu(), 
      GetArena());
  }
  ::memcpy(&hi_, &from.hi_,
    static_cast<size_t>(reinterpret_cast<char*>(&rcu_) -
    reinterpret_cast<char*>(&hi_)) + sizeof(rcu_));
  // @@protoc_insertion_point(copy_constructor:monitor.proto.SoftIrq)
}

void SoftIrq::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SoftIrq_cpu_5fsoftirq_2eproto.base);
  cpu_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&hi_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&rcu_) -
      reinterpret_cast<char*>(&hi_)) + sizeof(rcu_));
}

SoftIrq::~SoftIrq() {
  // @@protoc_insertion_point(destructor:monitor.proto.SoftIrq)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SoftIrq::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  cpu_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SoftIrq::ArenaDtor(void* object) {
  SoftIrq* _this = reinterpret_cast< SoftIrq* >(object);
  (void)_this;
}
void SoftIrq::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SoftIrq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SoftIrq& SoftIrq::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SoftIrq_cpu_5fsoftirq_2eproto.base);
  return *internal_default_instance();
}


void SoftIrq::Clear() {
// @@protoc_insertion_point(message_clear_start:monitor.proto.SoftIrq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cpu_.ClearToEmpty();
  ::memset(&hi_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rcu_) -
      reinterpret_cast<char*>(&hi_)) + sizeof(rcu_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SoftIrq::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string cpu = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_cpu();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "monitor.proto.SoftIrq.cpu"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float hi = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          hi_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float timer = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          timer_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float net_tx = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          net_tx_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float net_rx = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          net_rx_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float block = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 53)) {
          block_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float irq_poll = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 61)) {
          irq_poll_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float tasklet = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 69)) {
          tasklet_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float sched = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 77)) {
          sched_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float hrtimer = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 85)) {
          hrtimer_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float rcu = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 93)) {
          rcu_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SoftIrq::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:monitor.proto.SoftIrq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string cpu = 1;
  if (this->cpu().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_cpu().data(), static_cast<int>(this->_internal_cpu().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "monitor.proto.SoftIrq.cpu");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_cpu(), target);
  }

  // float hi = 2;
  if (!(this->hi() <= 0 && this->hi() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_hi(), target);
  }

  // float timer = 3;
  if (!(this->timer() <= 0 && this->timer() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_timer(), target);
  }

  // float net_tx = 4;
  if (!(this->net_tx() <= 0 && this->net_tx() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_net_tx(), target);
  }

  // float net_rx = 5;
  if (!(this->net_rx() <= 0 && this->net_rx() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_net_rx(), target);
  }

  // float block = 6;
  if (!(this->block() <= 0 && this->block() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(6, this->_internal_block(), target);
  }

  // float irq_poll = 7;
  if (!(this->irq_poll() <= 0 && this->irq_poll() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(7, this->_internal_irq_poll(), target);
  }

  // float tasklet = 8;
  if (!(this->tasklet() <= 0 && this->tasklet() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(8, this->_internal_tasklet(), target);
  }

  // float sched = 9;
  if (!(this->sched() <= 0 && this->sched() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(9, this->_internal_sched(), target);
  }

  // float hrtimer = 10;
  if (!(this->hrtimer() <= 0 && this->hrtimer() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(10, this->_internal_hrtimer(), target);
  }

  // float rcu = 11;
  if (!(this->rcu() <= 0 && this->rcu() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(11, this->_internal_rcu(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:monitor.proto.SoftIrq)
  return target;
}

size_t SoftIrq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:monitor.proto.SoftIrq)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string cpu = 1;
  if (this->cpu().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cpu());
  }

  // float hi = 2;
  if (!(this->hi() <= 0 && this->hi() >= 0)) {
    total_size += 1 + 4;
  }

  // float timer = 3;
  if (!(this->timer() <= 0 && this->timer() >= 0)) {
    total_size += 1 + 4;
  }

  // float net_tx = 4;
  if (!(this->net_tx() <= 0 && this->net_tx() >= 0)) {
    total_size += 1 + 4;
  }

  // float net_rx = 5;
  if (!(this->net_rx() <= 0 && this->net_rx() >= 0)) {
    total_size += 1 + 4;
  }

  // float block = 6;
  if (!(this->block() <= 0 && this->block() >= 0)) {
    total_size += 1 + 4;
  }

  // float irq_poll = 7;
  if (!(this->irq_poll() <= 0 && this->irq_poll() >= 0)) {
    total_size += 1 + 4;
  }

  // float tasklet = 8;
  if (!(this->tasklet() <= 0 && this->tasklet() >= 0)) {
    total_size += 1 + 4;
  }

  // float sched = 9;
  if (!(this->sched() <= 0 && this->sched() >= 0)) {
    total_size += 1 + 4;
  }

  // float hrtimer = 10;
  if (!(this->hrtimer() <= 0 && this->hrtimer() >= 0)) {
    total_size += 1 + 4;
  }

  // float rcu = 11;
  if (!(this->rcu() <= 0 && this->rcu() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SoftIrq::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:monitor.proto.SoftIrq)
  GOOGLE_DCHECK_NE(&from, this);
  const SoftIrq* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SoftIrq>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:monitor.proto.SoftIrq)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:monitor.proto.SoftIrq)
    MergeFrom(*source);
  }
}

void SoftIrq::MergeFrom(const SoftIrq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:monitor.proto.SoftIrq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.cpu().size() > 0) {
    _internal_set_cpu(from._internal_cpu());
  }
  if (!(from.hi() <= 0 && from.hi() >= 0)) {
    _internal_set_hi(from._internal_hi());
  }
  if (!(from.timer() <= 0 && from.timer() >= 0)) {
    _internal_set_timer(from._internal_timer());
  }
  if (!(from.net_tx() <= 0 && from.net_tx() >= 0)) {
    _internal_set_net_tx(from._internal_net_tx());
  }
  if (!(from.net_rx() <= 0 && from.net_rx() >= 0)) {
    _internal_set_net_rx(from._internal_net_rx());
  }
  if (!(from.block() <= 0 && from.block() >= 0)) {
    _internal_set_block(from._internal_block());
  }
  if (!(from.irq_poll() <= 0 && from.irq_poll() >= 0)) {
    _internal_set_irq_poll(from._internal_irq_poll());
  }
  if (!(from.tasklet() <= 0 && from.tasklet() >= 0)) {
    _internal_set_tasklet(from._internal_tasklet());
  }
  if (!(from.sched() <= 0 && from.sched() >= 0)) {
    _internal_set_sched(from._internal_sched());
  }
  if (!(from.hrtimer() <= 0 && from.hrtimer() >= 0)) {
    _internal_set_hrtimer(from._internal_hrtimer());
  }
  if (!(from.rcu() <= 0 && from.rcu() >= 0)) {
    _internal_set_rcu(from._internal_rcu());
  }
}

void SoftIrq::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:monitor.proto.SoftIrq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SoftIrq::CopyFrom(const SoftIrq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:monitor.proto.SoftIrq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SoftIrq::IsInitialized() const {
  return true;
}

void SoftIrq::InternalSwap(SoftIrq* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  cpu_.Swap(&other->cpu_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(SoftIrq, rcu_)
      + sizeof(SoftIrq::rcu_)
      - PROTOBUF_FIELD_OFFSET(SoftIrq, hi_)>(
          reinterpret_cast<char*>(&hi_),
          reinterpret_cast<char*>(&other->hi_));
}

::PROTOBUF_NAMESPACE_ID::Metadata SoftIrq::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace monitor
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::monitor::proto::SoftIrq* Arena::CreateMaybeMessage< ::monitor::proto::SoftIrq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::monitor::proto::SoftIrq >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
