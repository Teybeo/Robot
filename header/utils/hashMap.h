#ifndef _HASH_MAP_GUARD
#define _HASH_MAP_GUARD

#include "utils/vec3.h"
#include "utils/vec2.h"

#include <stdbool.h>

typedef struct _Vertex {
    Vec3 pos;
    Vec3 normal;
    Vec2 uv;
    Vec3 tangent;
    Vec3 bitangent;
} Vertex;

typedef struct _Bucket {

    Vertex key;           // Non-hashed key of this bucket
    int value;            // Value associated to the key
    bool used;            // Flag indicating if this bucket has been set
    struct _Bucket* next; // Storage for collisions

} Bucket;

typedef struct _HashMap {

    Bucket* buckets;
    unsigned int size;         // Max number of buckets
    unsigned int wide_size;    // Max number of buckets * factor, to reduce collisions
    unsigned int used_buckets; // Number of buckets currently used
    unsigned int collisions;   // Number of collision

} HashMap;

HashMap* HashMap_create(unsigned int max_size);
void HashMap_add(HashMap* hashmap, Vertex key, int value);
int HashMap_get(HashMap* hashmap, Vertex key);
void HashMap_Delete(HashMap* hashmap);
void HashMap_printCollisions(HashMap* hashmap);

#endif // HASH_MAP

