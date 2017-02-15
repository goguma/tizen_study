#ifndef __threadtest_H__
#define __threadtest_H__

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>
#include <tizen.h>

#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "threadtest"

#if !defined(PACKAGE)
#define PACKAGE "org.example.threadtest"
#endif

typedef struct appdata {
	Evas_Object *win;
	Evas_Object *conform;
	Evas_Object *label;
	struct {
		Eina_Bool network_connected;
		int network;
	} network;
} appdata_s;

void *
_set_label_text_network_update(void *data);

#endif /* __threadtest_H__ */
