#ifndef BUFFER_H
    #define BUFFER_H

#ifndef SizeOfBuffer
    #define SizeOfBuffer 128
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

    inline bool Push(char Letter);

    inline char *PullAll();

    inline bool UnlockBuffer(char UnlockerDescriptor);

    inline bool LockBuffer(char LockerDescriptor);

    inline bool GetResponceToUseBuffer( char DescriptorOfUser);

};

#endif