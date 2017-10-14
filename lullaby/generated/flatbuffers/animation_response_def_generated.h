// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ANIMATIONRESPONSEDEF_LULL_H_
#define FLATBUFFERS_GENERATED_ANIMATIONRESPONSEDEF_LULL_H_

#include "flatbuffers/flatbuffers.h"

#include "animation_def_generated.h"
#include "common_generated.h"
#include "dispatcher_def_generated.h"
#include "variant_def_generated.h"

namespace lull {

struct AnimationResponseDef;

/// A response that plays an animation based on an input event.  (For example,
/// moving an Entity when it is hovered.)
struct AnimationResponseDef FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "lull.AnimationResponseDef";
  }
  enum {
    VT_INPUTS = 4,
    VT_ANIMATION = 6
  };
  /// One or more inputs that trigger the response.  See dispatcher_def.fbs for
  /// more information about the EventDef table.
  const flatbuffers::Vector<flatbuffers::Offset<EventDef>> *inputs() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<EventDef>> *>(VT_INPUTS);
  }
  /// Animations to play based on the input.
  const AnimationDef *animation() const {
    return GetPointer<const AnimationDef *>(VT_ANIMATION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_INPUTS) &&
           verifier.Verify(inputs()) &&
           verifier.VerifyVectorOfTables(inputs()) &&
           VerifyOffset(verifier, VT_ANIMATION) &&
           verifier.VerifyTable(animation()) &&
           verifier.EndTable();
  }
};

struct AnimationResponseDefBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_inputs(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EventDef>>> inputs) {
    fbb_.AddOffset(AnimationResponseDef::VT_INPUTS, inputs);
  }
  void add_animation(flatbuffers::Offset<AnimationDef> animation) {
    fbb_.AddOffset(AnimationResponseDef::VT_ANIMATION, animation);
  }
  explicit AnimationResponseDefBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimationResponseDefBuilder &operator=(const AnimationResponseDefBuilder &);
  flatbuffers::Offset<AnimationResponseDef> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<AnimationResponseDef>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimationResponseDef> CreateAnimationResponseDef(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EventDef>>> inputs = 0,
    flatbuffers::Offset<AnimationDef> animation = 0) {
  AnimationResponseDefBuilder builder_(_fbb);
  builder_.add_animation(animation);
  builder_.add_inputs(inputs);
  return builder_.Finish();
}

inline flatbuffers::Offset<AnimationResponseDef> CreateAnimationResponseDefDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<EventDef>> *inputs = nullptr,
    flatbuffers::Offset<AnimationDef> animation = 0) {
  return lull::CreateAnimationResponseDef(
      _fbb,
      inputs ? _fbb.CreateVector<flatbuffers::Offset<EventDef>>(*inputs) : 0,
      animation);
}

}  // namespace lull

#endif  // FLATBUFFERS_GENERATED_ANIMATIONRESPONSEDEF_LULL_H_