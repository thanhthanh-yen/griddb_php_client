/*
    Copyright (c) 2017 TOSHIBA Digital Solutions Corporation.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _STORE_FACTORY_H_
#define _STORE_FACTORY_H_
#define CLIENT_VERSION "GridDB PHP Client 0.8"

#include <map>
#include <string>

#include "gridstore.h"
#include "Store.h"
#include "GSException.h"
#include "Util.h"

namespace griddb {

/**
 * Class GridStoreFactory to contain GSGridStoreFactory object.
 * This class is implemented as singleton.
 */
class StoreFactory {
 private:
    GSGridStoreFactory *mFactory;

 public:
    ~StoreFactory();
    void close(GSBool allRelated = GS_FALSE);
    static StoreFactory* get_instance();
    Store* get_store(const char *host, int32_t port, const char *cluster_name,
                     const char *database, const char *username,
                     const char *password, const char *notification_member,
                     const char *notification_provider);
    string get_version();

 private:
    StoreFactory();
    void set_property_entry(GSPropertyEntry *prop, const char *name,
                            const char *value);
    bool check_multicast(const char *address);
    void set_factory(GSGridStoreFactory *factory);
};

} /* namespace griddb */

#endif
