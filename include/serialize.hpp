#ifndef DPP_SERIALIZATION
#define DPP_SERIALIZATION

#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include <memory>
#include <stdexcept>

#include "cereal/details/helpers.hpp"
#include "macros.hpp"


NAMESPACE_DPP_BEGIN
    NAMESPACE_BEGIN(serialize)
        template<typename T> T load(std::istream &istream,
                                    void (*failed)(cereal::Exception &) = []() {}) {
            try {
                cereal::PortableBinaryInputArchive archive(istream);
                // cereal::JSONInputArchive archive(istream);
                T object {};
                archive(object);

                return object;
            } catch (cereal::Exception &e) {
                failed(e);
                throw std::runtime_error("serialize: failed");
            }
        }

        template<typename T> STATUS save(std::ostream &fs, const T &object,
                                        void (*failed)(cereal::Exception &) = [](cereal::Exception &) {}) {
            try {
                cereal::PortableBinaryOutputArchive archive(fs);
                // cereal::JSONOutputArchive archive(fs);
                archive(object);
            } catch (cereal::Exception &e) {
                failed(e);
                return STATUS_FAILED;
            }


            return STATUS_SUCCESS;
        }
    NAMESPACE_END
NAMESPACE_DPP_END

#endif // !DPP_SERIALIZATION
