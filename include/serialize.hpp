#ifndef DPP_SERIALIZATION
#define DPP_SERIALIZATION

#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include <stdexcept>

#include "cereal/details/helpers.hpp"
#include "macros.hpp"


NAMESPACE_DPP_BEGIN
    NAMESPACE_BEGIN(serialize)
        template<typename T, typename Archive = cereal::PortableBinaryInputArchive> T load(std::istream &istream,
                                    void (*failed)(cereal::Exception &) = []() {}) {
            try {
                Archive archive(istream);
                T object {};
                archive(object);

                return object;
            } catch (cereal::Exception &e) {
                failed(e);
                throw std::runtime_error("serialize: failed");
            }
        }

        template<typename T, typename Archive = cereal::PortableBinaryOutputArchive> STATUS save(std::ostream &fs, const T &object,
                                        void (*failed)(cereal::Exception &) = [](cereal::Exception &) {}) {
            try {
                Archive archive(fs);
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
