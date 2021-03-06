#ifndef NGTK_H_
#define NGTK_H_

#include <v8.h>
#include <glib.h>
#include <gtk/gtk.h>

namespace ngtk {

#define NGTK_DEFINE_CONSTANT(target, name, constant)                      \
  (target)->Set(v8::String::NewSymbol(name),                              \
                v8::Integer::New(constant),                               \
                static_cast<v8::PropertyAttribute>(v8::ReadOnly|v8::DontDelete))

#define NGTK_SET_PROTOTYPE_METHOD(templ, name, callback)                  \
do {                                                                      \
  v8::Local<v8::Signature> __callback##_SIG = v8::Signature::New(templ);  \
  v8::Local<v8::FunctionTemplate> __callback##_TEM =                      \
    v8::FunctionTemplate::New(callback, v8::Handle<v8::Value>(),          \
                          __callback##_SIG);                              \
  templ->PrototypeTemplate()->Set(v8::String::NewSymbol(name),            \
                                  __callback##_TEM);                      \
} while (0)

#define NGTK_SET_METHOD(obj, name, callback)                              \
  obj->Set(v8::String::NewSymbol(name),                                   \
      v8::FunctionTemplate::New(callback)->GetFunction())

} // namespace ngtk

#endif
