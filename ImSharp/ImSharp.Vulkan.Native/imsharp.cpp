#include "imsharp.hpp"

namespace {

void* dummy_address = reinterpret_cast<void*>(0xdeadbeef);

} // namespace

struct imsharp_context final
{
};

struct imsharp_frame final
{
    imsharp_frame(imsharp_context*) {}
};

imsharp_context* imsharp_setup()
{
    return new imsharp_context{};
}

void imsharp_cleanup(imsharp_context* context)
{
    delete context;
}

imsharp_frame* imsharp_begin_frame(imsharp_context* context)
{
    return new imsharp_frame(context);
}

void imsharp_end_frame(imsharp_context* context, imsharp_frame* frame)
{
    delete frame;
}
