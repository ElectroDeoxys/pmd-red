#include "global.h"
#include "memory.h"

extern u32 gUnknown_80B7F14;
extern u32 gUnknown_80B7F88;
extern const char gLocateSetErrorMessage[];
extern struct HeapDescriptor gMainHeapDescriptor;
extern const char gLocalCreateErrorMessage[];
extern s32 MemorySearchFromBack(struct HeapDescriptor *heap, s32, s32);
extern s32 MemorySearchFromFront(struct HeapDescriptor *heap, s32, s32);
extern struct HeapDescriptor * _LocateSetBack(struct HeapDescriptor *, u32, u32, u32, u32);
extern struct HeapDescriptor * _LocateSetFront(struct HeapDescriptor *, u32, u32, u32, u32);
void DoFree(struct HeapDescriptor *, void *);
void *DoAlloc(struct HeapDescriptor *, s32, u32);
extern struct HeapDescriptor *DoCreateSubHeap(u32 *, u32);

void FatalError(u32 *, const char *, ...) __attribute__((noreturn));


s32 _LocateSet(struct HeapDescriptor *heap, s32 size, s32 group)
{
  s32 index;
  struct HeapDescriptor * uVar2;
  s32 atb;
  
  if (heap == NULL) {
    heap = &gMainHeapDescriptor;
  }

  // Set some sort flag/attr?
  atb = group >> 8 | 1;

  // Reset it?
  group = group & 0xff;

  if ((atb & 2) != 0) {
    index = MemorySearchFromFront(heap,atb,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetFront(heap,index,atb,size,group);
    return uVar2->freeCount;
  }
  else {
    index = MemorySearchFromBack(heap,atb,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetBack(heap,index,atb,size,group);
    return uVar2->freeCount;
  }

error:
    // LocateSet [%p] buffer %8x size can't locate
        // atb %02x grp %3d
   FatalError(&gUnknown_80B7F14,
                 gLocateSetErrorMessage,
                 heap,size,atb,group);
}

void *MemoryAlloc(s32 size, s32 b)
{
    DoAlloc(&gMainHeapDescriptor, size, b);
}

void MemoryFree(void *a)
{
    DoFree(&gMainHeapDescriptor, a);
}

struct HeapDescriptor *MemoryLocate_LocalCreate(struct HeapDescriptor *parentHeap,u32 size,u32 param_3,u32 group)
{
  int index;
  struct HeapDescriptor *iVar2;
  struct HeapDescriptor *iVar3;
  s32 local_1c[2];
  
  if (parentHeap == NULL) {
    parentHeap = &gMainHeapDescriptor;
  }

  index = MemorySearchFromBack(parentHeap,9,size);
  if (index < 0)
    // Memroy LocalCreate buffer %08x size can't locate
    FatalError(&gUnknown_80B7F88,gLocalCreateErrorMessage,size);

  iVar2 = _LocateSetBack(parentHeap,index,9,size,group);
  local_1c[0] = iVar2->freeCount;
  local_1c[1] = iVar2->freeListLength;

  iVar3 = DoCreateSubHeap(local_1c,param_3);
  iVar3->parentHeap = parentHeap;
  return iVar3;
}
