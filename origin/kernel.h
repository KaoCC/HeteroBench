/* HEADER FILE GENERATED BY snack VERSION 0.9.0 */
/* THIS FILE:  /home/liu/BinarySearchTree/kernel.h  */
/* INPUT FILE: /home/liu/BinarySearchTree/kernel.cl  */
#ifdef __cplusplus
#define _CPPSTRING_ "C" 
#endif
#ifndef __cplusplus
#define _CPPSTRING_ 
#endif
#ifndef __SNK_DEFS
#define SNK_MAX_STREAMS 8 
#define SNK_MAX_TASKS 100001
extern _CPPSTRING_ void stream_sync(const int stream_num);

#define SNK_ORDERED 1
#define SNK_UNORDERED 0

#include <stdint.h>
#ifndef HSA_RUNTIME_INC_HSA_H_
typedef struct hsa_signal_s { uint64_t handle; } hsa_signal_t;
#endif

typedef struct snk_task_s snk_task_t;
struct snk_task_s { 
   hsa_signal_t signal ; 
   snk_task_t* next;
};

typedef struct snk_lparm_s snk_lparm_t;
struct snk_lparm_s { 
   int ndim;                  /* default = 1 */
   size_t gdims[3];           /* NUMBER OF THREADS TO EXECUTE MUST BE SPECIFIED */ 
   size_t ldims[3];           /* Default = {64} , e.g. 1 of 8 CU on Kaveri */
   int stream;                /* default = -1 , synchrnous */
   int barrier;               /* default = SNK_UNORDERED */
   int acquire_fence_scope;   /* default = 2 */
   int release_fence_scope;   /* default = 2 */
   snk_task_t *requires ;     /* Linked list of required parent tasks, default = NULL  */
   snk_task_t *needs ;        /* Linked list of parent tasks where only one must complete, default=NULL */
} ;

/* This string macro is used to declare launch parameters set default values  */
#define SNK_INIT_LPARM(X,Y) snk_lparm_t * X ; snk_lparm_t  _ ## X ={.ndim=1,.gdims={Y},.ldims={64},.stream=-1,.barrier=SNK_UNORDERED,.acquire_fence_scope=2,.release_fence_scope=2,.requires=NULL,.needs=NULL} ; X = &_ ## X ;
 
/* Equivalent host data types for kernel data types */
typedef struct snk_image3d_s snk_image3d_t;
struct snk_image3d_s { 
   unsigned int channel_order; 
   unsigned int channel_data_type; 
   size_t width, height, depth;
   size_t row_pitch, slice_pitch;
   size_t element_size;
   void *data;
};

#define __SNK_DEFS
#endif
extern _CPPSTRING_ void Find(void* node,void* out,int* key_list, const snk_lparm_t * lparm);
extern _CPPSTRING_ void Insert(void* rootNode,void* dataNode, const snk_lparm_t * lparm);
