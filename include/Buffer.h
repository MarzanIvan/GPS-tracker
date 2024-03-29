#ifndef BUFFER_H
    #define BUFFER_H

#ifndef SizeOfBuffer
    #define SizeOfBuffer 255
#endif

enum States {
    FREE, LOCKED
};

struct Stream_Buffer {
    char Stack[SizeOfBuffer];
    unsigned char IndexOfNextElement;
    char Descriptor;
    enum States StateOfBuffer;
    Stream_Buffer() {
        *Stack = 0;
        IndexOfNextElement = 0;
        StateOfBuffer = FREE;
    }

    ~Stream_Buffer() {
        
    }

inline bool Push(char Letter) {
    if (IndexOfNextElement < SizeOfBuffer) {
        Stack[IndexOfNextElement++] = Letter;
        Stack[IndexOfNextElement] = '\0';
        return true;
    }
    else {
        return false;
    }
}

inline char *PullAll() {
    if (IndexOfNextElement > 0) {
        return Stack;
    }
    else {
        return '\0';
    }
}

inline bool UnlockBuffer(char UnlockerDescriptor) {
    if (UnlockerDescriptor != Descriptor) {
        return false;
    }
    Descriptor = 0;
    StateOfBuffer = FREE; 
    return true;
}

inline bool LockBuffer(char LockerDescriptor) {
    if (StateOfBuffer != FREE) {
        return false;
    }
    Descriptor = LockerDescriptor; 
    StateOfBuffer = LOCKED;
    return true;
}

inline bool GetResponceToUseBuffer( char DescriptorOfUser) {
    if (DescriptorOfUser == Descriptor) {
        return true;
    } else {
        return false;
    }
}

};

#endif