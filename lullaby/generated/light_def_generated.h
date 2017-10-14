// Autogenerated code.  Do not edit.
#ifndef _LULLABY_LULLABY_GENERATED_LIGHT_DEF_GENERATED_H_
#define _LULLABY_LULLABY_GENERATED_LIGHT_DEF_GENERATED_H_

#include <type_traits>
#include <memory>
#include "flatbuffers/light_def_generated.h"
#include "lullaby/util/common_types.h"
#include "lullaby/util/color.h"
#include "lullaby/util/math.h"
#include "lullaby/util/optional.h"
#include "lullaby/util/typeid.h"
#include "common_generated.h"

namespace lull {
class ShadowMapDefT;
class ShadowDefT;
class AmbientLightDefT;
class DirectionalLightDefT;
class PointLightDefT;
class LightableDefT;
class ShadowMapDefT {
 public:
  using FlatBufferType = ShadowMapDef;

  ShadowMapDefT() {}

  int32_t shadow_resolution = 512;
  float shadow_min_distance = 1.0f;
  float shadow_max_distance = 10.0f;
  float shadow_volume = 10.0f;

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class ShadowDefT {
 public:
  using FlatBufferType = ShadowDef;
  static const uint8_t kNone = ShadowDef_NONE;

  ShadowDefT() {}
  ~ShadowDefT() { reset(); }

  ShadowDefT(const ShadowDefT& rhs) { assign(rhs); }
  ShadowDefT& operator=(const ShadowDefT& rhs) {
    assign(rhs);
    return *this;
  }

  void reset();

  FlatBufferType type() const {
    return type_;
  }

  template <typename T>
  T* get() {
    return type_ == get_type<T>() ?
        reinterpret_cast<T*>(&data_) : nullptr;
  }

  template <typename T>
  const T* get() const {
    return type_ == get_type<T>() ?
        reinterpret_cast<const T*>(&data_) : nullptr;
  }

  template <typename T>
  T* set();

  template <typename Archive>
  void SerializeFlatbuffer(FlatBufferType type, Archive archive);

 private:
  void assign(const ShadowDefT& rhs);

  template <typename T>
  void destroy() {
    reinterpret_cast<T*>(&data_)->~T();
  }

  template <typename T>
  static FlatBufferType get_type() {
    return ShadowDef_NONE;
  }

  template <typename T>
  using Store = std::aligned_storage<sizeof(T), alignof(T)>;
  union Buffer {
    Store<lull::ShadowMapDefT>::type ShadowMapDef_;
  };
  Buffer data_;
  FlatBufferType type_ = ShadowDef_NONE;
};

class AmbientLightDefT {
 public:
  using FlatBufferType = AmbientLightDef;

  AmbientLightDefT() {}

  lull::HashValue group = 0;
  lull::Color4ub color = {0, 0, 0, 0};

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class DirectionalLightDefT {
 public:
  using FlatBufferType = DirectionalLightDef;

  DirectionalLightDefT() {}

  lull::HashValue group = 0;
  lull::Color4ub color = {0, 0, 0, 0};
  float exponent = 0.0f;
  lull::ShadowDefT shadow_def;
  mathfu::quat rotation = {0.f, 0.f, 0.f, 1.f};

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class PointLightDefT {
 public:
  using FlatBufferType = PointLightDef;

  PointLightDefT() {}

  lull::HashValue group = 0;
  lull::Color4ub color = {0, 0, 0, 0};
  float intensity = 0.0f;
  float exponent = 0.0f;
  mathfu::vec3 position = {0.f, 0.f, 0.f};

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class LightableDefT {
 public:
  using FlatBufferType = LightableDef;

  LightableDefT() {}

  lull::HashValue group = 0;
  int32_t max_ambient_lights = 0;
  int32_t max_directional_lights = 0;
  int32_t max_point_lights = 0;
  lull::ShadowInteraction shadow_interaction = lull::ShadowInteraction_None;
  int32_t shadow_sampler = 5;
  std::string depth_shader;

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

template <typename Archive>
void ShadowMapDefT::SerializeFlatbuffer(Archive archive) {
  archive.Scalar(&shadow_resolution, 4, 512);
  archive.Scalar(&shadow_min_distance, 6, 1.0f);
  archive.Scalar(&shadow_max_distance, 8, 10.0f);
  archive.Scalar(&shadow_volume, 10, 10.0f);
}

inline void ShadowDefT::reset() {
  switch (type_) {
    case ShadowDef_ShadowMapDef: {
      destroy<lull::ShadowMapDefT>();
      break;
    }
    default:
      break;
  }
  type_ = ShadowDef_NONE;
}

inline void ShadowDefT::assign(const ShadowDefT& rhs) {
  reset();
  switch (rhs.type_) {
    case ShadowDef_ShadowMapDef: {
      *set<lull::ShadowMapDefT>() = *rhs.get<lull::ShadowMapDefT>();
      break;
    }
    default:
      break;
  }
}

template <typename T>
T* ShadowDefT::set() {
  reset();
  type_ = get_type<T>();
  if (type_ != kNone) {
    return new (&data_) T();
  }
  return nullptr;
}

template <>
inline ShadowDef ShadowDefT::get_type<lull::ShadowMapDefT>() {
  return ShadowDef_ShadowMapDef;
}


template <typename Archive>
void ShadowDefT::SerializeFlatbuffer(FlatBufferType type, Archive archive) {
  switch (type) {
    case ShadowDef_ShadowMapDef: {
      if (archive.IsDestructive()) {
        set<lull::ShadowMapDefT>()->SerializeFlatbuffer(archive);
      } else {
        get<lull::ShadowMapDefT>()->SerializeFlatbuffer(archive);
      }
      break;
    }
    default:
      if (archive.IsDestructive()) {
        reset();
      }
      break;
  }
}

template <typename Archive>
void AmbientLightDefT::SerializeFlatbuffer(Archive archive) {
  archive.Scalar(&group, 4, 0);
  archive.NativeStruct(&color, 6);
}

template <typename Archive>
void DirectionalLightDefT::SerializeFlatbuffer(Archive archive) {
  archive.Union(&shadow_def, 12, lull::ShadowDefT::kNone);
  archive.Scalar(&group, 4, 0);
  archive.NativeStruct(&color, 6);
  archive.Scalar(&exponent, 8, 0.0f);
  archive.NativeStruct(&rotation, 14);
}

template <typename Archive>
void PointLightDefT::SerializeFlatbuffer(Archive archive) {
  archive.Scalar(&group, 4, 0);
  archive.NativeStruct(&color, 6);
  archive.Scalar(&intensity, 8, 0.0f);
  archive.Scalar(&exponent, 10, 0.0f);
  archive.NativeStruct(&position, 12);
}

template <typename Archive>
void LightableDefT::SerializeFlatbuffer(Archive archive) {
  archive.String(&depth_shader, 16);
  archive.Scalar(&group, 4, 0);
  archive.Scalar(&max_ambient_lights, 6, 0);
  archive.Scalar(&max_directional_lights, 8, 0);
  archive.Scalar(&max_point_lights, 10, 0);
  int32_t _shadow_interaction = static_cast<int32_t>(shadow_interaction);
  archive.Scalar(&_shadow_interaction, 12, lull::ShadowInteraction_None);
  shadow_interaction = static_cast<lull::ShadowInteraction>(_shadow_interaction);
  archive.Scalar(&shadow_sampler, 14, 5);
}

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::ShadowMapDefT);
LULLABY_SETUP_TYPEID(lull::ShadowDefT);
LULLABY_SETUP_TYPEID(lull::AmbientLightDefT);
LULLABY_SETUP_TYPEID(lull::DirectionalLightDefT);
LULLABY_SETUP_TYPEID(lull::PointLightDefT);
LULLABY_SETUP_TYPEID(lull::ShadowInteraction);
LULLABY_SETUP_TYPEID(lull::LightableDefT);

#endif  // _LULLABY_LULLABY_GENERATED_LIGHT_DEF_GENERATED_H_
