/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) 2023 Marvell.
 */

#ifndef _MLDPC_H_
#define _MLDPC_H_

#include <stdint.h>
#include <stdio.h>

enum buffer_type { input_quantize = 0, input_dequantize, output_quantize, output_dequantize };

int mrvl_ml_init(int argc, char *argv[]);

int mrvl_ml_init_mt(int argc, char *argv[], int num_threads);

int mrvl_ml_finish(void);

int mrvl_ml_model_load(char *model_buffer, int model_size);

int mrvl_ml_model_unload(int model_id);

void *mrvl_ml_io_alloc(int model_id, enum buffer_type buff_type, uint64_t *size);

void mrvl_ml_io_free(int model_id, enum buffer_type buff_type, void *addr);

int mrvl_ml_model_quantize(int model_id, void *dbuffer, void *qbuffer);

int mrvl_ml_model_dequantize(int model_id, void *qbuffer, void *dbuffer);

int mrvl_ml_model_run(int model_id, void *input_buffer, void *output_buffer, int num_batches);

int mrvl_ml_model_run_mt(int model_id, void *input_buffer, void *output_buffer, int num_batches,
			 int thread_id);

#endif /* _MLDPC_H_ */