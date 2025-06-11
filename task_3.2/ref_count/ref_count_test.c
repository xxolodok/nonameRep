#include "ref_count.h"
#include <stdlib.h>
#include <assert.h>

typedef struct {
	int value;
} test_obj_t;

int main(void) {
	assert(ref_count_init(2) == 0);

	test_obj_t *obj = malloc(sizeof(test_obj_t));
	assert(obj != NULL);
	obj->value = 42;

	ref_count_t *ref = ref_count_create(obj);
	assert(ref != NULL);
	assert(ref->count == 1);
	assert(ref->object == obj);

	assert(ref_count_retain(ref) == 0);
	assert(ref->count == 2);

	assert(ref_count_release(ref) == 0);
	assert(ref->count == 1);

	assert(ref_count_release(ref) == 0);

	ref_count_destroy();

	return 0;
}
