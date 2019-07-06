/*
 * Copyright © 2017 Red Hat, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Christian J. Kellner <christian@kellner.me>
 */

#include "config.h"

#include "bolt-bouncer.h"

#include "bolt-log.h"
#include "bolt-str.h"

#include "bolt-exported.h"

#include <gio/gio.h>

static void     bouncer_initable_iface_init (GInitableIface *iface);


static gboolean bouncer_initialize (GInitable    *initable,
                                    GCancellable *cancellable,
                                    GError      **error);

struct _BoltBouncer
{
  GObject object;
};

G_DEFINE_TYPE_WITH_CODE (BoltBouncer, bolt_bouncer, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (G_TYPE_INITABLE,
                                                bouncer_initable_iface_init));


static void
bolt_bouncer_finalize (GObject *object)
{
}

static void
bolt_bouncer_init (BoltBouncer *bouncer)
{
}

static void
bolt_bouncer_class_init (BoltBouncerClass *klass)
{
}

static void
bouncer_initable_iface_init (GInitableIface *iface)
{
}

static gboolean
bouncer_initialize (GInitable    *initable,
                    GCancellable *cancellable,
                    GError      **error)
{
  return TRUE;
}

/* internal methods */

static gboolean
bolt_bouncer_check_action (BoltBouncer           *bnc,
                           GDBusMethodInvocation *inv,
                           const char            *action,
                           gboolean              *authorized,
                           GError               **error)
{
  return TRUE;
}

static gboolean
handle_authorize_method (BoltExported          *exported,
                         GDBusMethodInvocation *inv,
                         GError               **error,
                         gpointer               user_data)
{
  return TRUE;
}

static gboolean
handle_authorize_property (BoltExported          *exported,
                           const char            *name,
                           gboolean               setting,
                           GDBusMethodInvocation *inv,
                           GError               **error,
                           gpointer               user_data)
{
  return TRUE;
}

/* public methods */
BoltBouncer *
bolt_bouncer_new (GCancellable *cancellable,
                  GError      **error)
{
  return g_initable_new (BOLT_TYPE_BOUNCER,
                         cancellable, error,
                         NULL);
}

void
bolt_bouncer_add_client (BoltBouncer *bnc,
                         gpointer     client)
{
}
