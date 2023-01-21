#include "../include/Buffer.h"

inline bool Stream_Buffer::Push(char Letter) {
    if (IndexOfNextElement < SizeOfBuffer) {
        Stack[IndexOfNextElement++] = Letter;
        Stack[IndexOfNextElement] = '\0';
        return true;
    }
    else {
        return false;
    }
}

inline char *Stream_Buffer::PullAll() {
    if (IndexOfNextElement > 0) {
        return Stack;
    }
    else {
        return '\0';
    }
}

inline bool Stream_Buffer::UnlockBuffer(char UnlockerDescriptor) {
    if (UnlockerDescriptor != Descriptor) {
        return false;
    }
    StateOfBuffer = FREE; 
    return true;
}

inline bool Stream_Buffer::LockBuffer(char LockerDescriptor) {
    if (StateOfBuffer != FREE) {
        return false;
    }
    Descriptor = LockerDescriptor; 
    StateOfBuffer = LOCKED;
    return true;
}

inline bool Stream_Buffer::GetResponceToUseBuffer( char DescriptorOfUser) {
    if (DescriptorOfUser == Descriptor) {
        return true;
    } else {
        return false;
    }
}