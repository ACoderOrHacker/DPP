#include <boost/archive/basic_archive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "struct.hpp"

struct FileHeader {

};

class S_FObject {
public:
    struct FileHeader header;
    Array<Module> modules;
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

namespace dpp {
    namespace serialization {
        template<typename T> T *load(std::istream);

        template<typename T> STATUS save(std::ostream &, T *);
    }
}
