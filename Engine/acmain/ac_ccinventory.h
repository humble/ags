#ifndef __AC_CCINVENTORY_H
#define __AC_CCINVENTORY_H

struct CCInventory : AGSCCDynamicObject {

    // return the type name of the object
    virtual const char *GetType() {
        return "Inventory";
    }

    // serialize the object into BUFFER (which is BUFSIZE bytes)
    // return number of bytes used
    virtual int Serialize(const char *address, char *buffer, int bufsize) {
        ScriptInvItem *shh = (ScriptInvItem*)address;
        StartSerialize(buffer);
        SerializeInt(shh->id);
        return EndSerialize();
    }

    virtual void Unserialize(int index, const char *serializedData, int dataSize) {
        StartUnserialize(serializedData, dataSize);
        int num = UnserializeInt();
        ccRegisterUnserializedObject(index, &scrInv[num], this);
    }

};

#endif // __AC_CCINVENTORY_H