// Copyright © 2023. GothicKit Contributors
// SPDX-License-Identifier: MIT
#pragma once
#include "Api.h"
#include "Buffer.h"
#include "Vdf.h"

#include <stdint.h>

typedef struct PxInternal_Vm PxVm;
typedef struct PxInternal_VmInstance PxVmInstance;

typedef enum {
	PxVmInstanceTypeNpc = 1,
} PxVmInstanceType;

typedef void (*PxVmExternalCallback)(PxVm* vm);
typedef void (*PxVmExternalDefaultCallback)(PxVm* vm, char const* name);

// TODO
PXC_API PxVm* pxVmLoad(PxBuffer* buffer);
PXC_API PxVm* pxVmLoadFromVdf(PxVdf const* vdf, char const* name);
PXC_API void pxVmDestroy(PxVm* vm);

PXC_API PxVmInstance* pxVmStackPopInstance(PxVm* vm);
PXC_API char const* pxVmStackPopString(PxVm* vm);
PXC_API float pxVmStackPopFloat(PxVm* vm);
PXC_API int32_t pxVmStackPopInt(PxVm* vm);

PXC_API void pxVmStackPushInstance(PxVm* vm, PxVmInstance* instance);
PXC_API void pxVmStackPushString(PxVm* vm, char const* string);
PXC_API void pxVmStackPushFloat(PxVm* vm, float f);
PXC_API void pxVmStackPushInt(PxVm* vm, int i);

PXC_API void pxVmRegisterExternal(PxVm* vm, char const* name, PxVmExternalCallback cb);
PXC_API void pxVmRegisterExternalDefault(PxVm* vm, PxVmExternalDefaultCallback cb);

PXC_API PxVmInstance* pxVmGetGlobalSelf(PxVm* vm);
PXC_API PxVmInstance* pxVmGetGlobalOther(PxVm* vm);
PXC_API PxVmInstance* pxVmGetGlobalVictim(PxVm* vm);
PXC_API PxVmInstance* pxVmGetGlobalHero(PxVm* vm);
PXC_API PxVmInstance* pxVmGetGlobalItem(PxVm* vm);

PXC_API PxVmInstance* pxVmSetGlobalSelf(PxVm* vm, PxVmInstance* instance);
PXC_API PxVmInstance* pxVmSetGlobalOther(PxVm* vm, PxVmInstance* instance);
PXC_API PxVmInstance* pxVmSetGlobalVictim(PxVm* vm, PxVmInstance* instance);
PXC_API PxVmInstance* pxVmSetGlobalHero(PxVm* vm, PxVmInstance* instance);
PXC_API PxVmInstance* pxVmSetGlobalItem(PxVm* vm, PxVmInstance* instance);

PXC_API bool pxVmCallFunction(PxVm* vm, char const* func, ...);
PXC_API bool pxVmCallFunctionByIndex(PxVm* vm, uint32_t index, char const* args, ...);

PXC_API PxVmInstance* pxVmInstanceAllocate(PxVm* vm, char const* name, PxVmInstanceType type);
PXC_API PxVmInstance* pxVmInstanceInitialize(PxVm* vm, char const* name, PxVmInstanceType type, PxVmInstance* existing);

PXC_API uint32_t pxVmInstanceNpcGetNameLength(PxVmInstance const* instance);
PXC_API char const* pxVmInstanceNpcGetName(PxVmInstance const* instance, uint32_t i);
PXC_API int32_t pxVmInstanceNpcGetRoutine(PxVmInstance const* instance);
