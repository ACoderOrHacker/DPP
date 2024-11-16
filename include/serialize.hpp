#ifndef DPP_SERIALIZATION
#define DPP_SERIALIZATION

#include <cereal/archives/binary.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include "struct.hpp"

struct FileHeader {
    FileHeader() {
        MagicNumber = "DPPO";
    }

    std::string MagicNumber;
    Version version = dpp::get_version();
    Version LowestVersion = dpp::get_version();
};

class S_FObject {
public:
    S_FObject() {
        header.MagicNumber = "DPPO";
    }
public:
    struct FileHeader header;
    Array<std::string> modules;
    Array<Dpp_Object *> global_mapping;
    struct VMState state;
};

/*
 * @return: S_FObject *
 * return a zipped FObject * to serialization
 */
S_FObject *GetS_FObject(FObject *fObj) {
    S_FObject *s_fObj = new S_FObject;
    s_fObj->state = fObj->state;
    s_fObj->global_mapping = fObj->obj_map.getGlobalMapping();
    s_fObj->modules = fObj->modules;

    return s_fObj;
}

NAMESPACE_DPP_BEGIN
    NAMESPACE_BEGIN(serialize)
        template<typename T> T load(std::istream &istream) {
            cereal::BinaryInputArchive archive(istream);
            T object{};
            archive(object);

            return object;
        }

        template<typename T> STATUS save(std::ostream &fs, const T &object) {
            cereal::BinaryOutputArchive archive(fs);
            archive(object);

            return STATUS_SUCCESS;
        }
    NAMESPACE_END
NAMESPACE_DPP_END

#endif // !DPP_SERIALIZATION
