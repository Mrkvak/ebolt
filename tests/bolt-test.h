/*
 * Copyright © 2018 Red Hat, Inc
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

#pragma once

#include <glib.h>

typedef char *BoltTmpDir;

BoltTmpDir    bolt_tmp_dir_make (const char *pattern,
                                 GError    **error);

void          bolt_tmp_dir_destroy (BoltTmpDir dir);

G_DEFINE_AUTO_CLEANUP_FREE_FUNC (BoltTmpDir, bolt_tmp_dir_destroy, NULL)

/* helper macro */

/* *INDENT-OFF* */
#define bolt_assert_strv_equal(a, b, n) G_STMT_START {                                \
    const GStrv sa__ = (a);                                                           \
    const GStrv sb__ = (b);                                                           \
    guint al__ = a != NULL ? g_strv_length (sa__) : 0;                                \
    guint bl__ = b != NULL ? g_strv_length (sb__) : 0;                                \
    if (n > 0) {                                                                      \
        al__ = MIN ((guint) n, al__);                                                 \
        bl__ = MIN ((guint) n, bl__);                                                 \
      }                                                                               \
    if (al__ != bl__)                                                                 \
      g_assertion_message_cmpnum (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC,        \
                                  "len(" #a ") == len(" #b ")",                       \
                                  (long double) al__, "!=", (long double) bl__, 'i'); \
    else                                                                              \
      for (guint il__ = 0; il__ < al__; il__++)                                       \
        if (g_strcmp0 (sa__[il__], sb__[il__]) == 0) {; } else {                      \
          g_autofree char *va__ = NULL;                                               \
          va__ = g_strdup_printf (#a "[%u] != " #b "[%u]", il__, il__ );              \
          g_assertion_message_cmpstr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC,    \
                                      va__, sa__[il__], "!=", sb__[il__]);            \
        }                                                                             \
    } G_STMT_END
/* *INDENT-ON* */
