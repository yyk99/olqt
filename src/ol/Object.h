//
//
//

#ifndef OL_OBJECT_H
#define OL_OBJECT_H

#include <ol/observable.h>

#pragma warning ( disable : 4251 )

#include <string>
#include <map>

#include <QObject>

namespace ol {

class OLQT_EXPORT Object : public Observable {
public:
    Object();
    virtual ~Object();

    virtual property_val_t get(std::string key);
    virtual void notify(std::string key, property_val_t oldValue);
    virtual void set(std::string key, property_val_t value, bool opt_silent);
private:

    std::map<std::string, property_val_t> values_;
};

}

#endif
