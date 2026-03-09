// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef ATCOMMAND_HPP
#define ATCOMMAND_HPP

#include <string>

#include <common/cbasetypes.hpp>
#include <common/mmo.hpp>

class map_session_data;

#define MAX_MSG 2000
#define msg_txt(sd, msg_number) atcommand_msgsd((sd), (msg_number))

//global var
extern char atcommand_symbol;
extern char charcommand_symbol;
extern int32 atcmd_binding_count;

/**
 * msg_table[lang_id][msg_id]
 **/
extern char*** msg_table;
extern uint8 max_message_table;


enum AtCommandType : uint8 {
	COMMAND_ATCOMMAND = 1,
	COMMAND_CHARCOMMAND = 2,
} ;

typedef int32 (*AtCommandFunc)(const int32 fd, map_session_data* sd, const char* command, const char* message);

bool is_atcommand(const int32 fd, map_session_data* sd, const char* message, int32 type);

void do_init_atcommand(void);
void do_final_atcommand(void);
void atcommand_db_load_groups();

bool atcommand_exists(const char* name);
const char* atcommand_alias_lookup( const std::string& cmd );

// @commands (script based)
struct atcmd_binding_data {
	char command[50];
	char npc_event[EVENT_NAME_LENGTH];
	int32 level;
	int32 level2;
};
extern struct atcmd_binding_data** atcmd_binding;
struct atcmd_binding_data* get_atcommandbind_byname(const char* name);

const char* atcommand_msg(int32 msg_number);
const char* atcommand_msgsd(const map_session_data *sd, int32 msg_number);
void atcommand_expand_message_table();
void atcommand_msg_set(uint8 lang_id, uint16 num, char *ptr);

bool msg_config_read(const char *cfg_name, bool allow_override, bool store_messages = true);
bool msg_config_reload(void);
void do_final_msg();

#endif /* ATCOMMAND_HPP */
