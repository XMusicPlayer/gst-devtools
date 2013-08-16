/* GStreamer
 * Copyright (C) 2013 Thiago Santos <thiago.sousa.santos@collabora.com>
 *
 * gst-validate-runner.h - Validate Runner class
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_VALIDATE_RUNNER_H__
#define __GST_VALIDATE_RUNNER_H__

#include <glib-object.h>
#include <gst/gst.h>

#include "gst-validate-report.h"

G_BEGIN_DECLS

/* forward declaration */
typedef struct _GstValidateScenario GstValidateScenario;

#define GST_TYPE_VALIDATE_RUNNER			(gst_validate_runner_get_type ())
#define GST_IS_VALIDATE_RUNNER(obj)		        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_VALIDATE_RUNNER))
#define GST_IS_VALIDATE_RUNNER_CLASS(klass)	        (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_VALIDATE_RUNNER))
#define GST_VALIDATE_RUNNER_GET_CLASS(obj)	        (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_VALIDATE_RUNNER, GstValidateRunnerClass))
#define GST_VALIDATE_RUNNER(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_VALIDATE_RUNNER, GstValidateRunner))
#define GST_VALIDATE_RUNNER_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_VALIDATE_RUNNER, GstValidateRunnerClass))
#define GST_VALIDATE_RUNNER_CAST(obj)                 ((GstValidateRunner*)(obj))
#define GST_VALIDATE_RUNNER_CLASS_CAST(klass)         ((GstValidateRunnerClass*)(klass))

typedef struct _GstValidateRunner GstValidateRunner;
typedef struct _GstValidateRunnerClass GstValidateRunnerClass;

/* TODO hide this to be opaque? */
/**
 * GstValidateRunner:
 *
 * GStreamer Validate Runner class.
 *
 * Class that manages a Validate test run for some pipeline
 */
struct _GstValidateRunner {
  GObject 	 object;

  gboolean       setup;

  /*< private >*/
  GSList *reports;
};

/**
 * GstValidateRunnerClass:
 * @parent_class: parent
 *
 * GStreamer Validate Runner object class.
 */
struct _GstValidateRunnerClass {
  GObjectClass	parent_class;
};

/* normal GObject stuff */
GType		gst_validate_runner_get_type		(void);

GstValidateRunner *   gst_validate_runner_new               (void);

void            gst_validate_runner_add_report  (GstValidateRunner * runner, GstValidateReport * report);

guint           gst_validate_runner_get_reports_count (GstValidateRunner * runner);
GSList *        gst_validate_runner_get_reports (GstValidateRunner * runner);

G_END_DECLS

#endif /* __GST_VALIDATE_RUNNER_H__ */
