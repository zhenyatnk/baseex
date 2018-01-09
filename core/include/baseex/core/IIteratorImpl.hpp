#pragma once

#include <baseex/core/IIterator.hpp>
#include <baseex/core/IStream.hpp>

#include <memory>

namespace baseex {
namespace core {

BASEEX_CORE_EXPORT baseex::core::TIterator<baseex::core::IStreamBuffer::Ptr>::Ptr CreateBaseIterator(baseex::core::IStream::Ptr, const char aDelimeter);

}
}
