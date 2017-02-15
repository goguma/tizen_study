/*
 * networktest.c
 *
 *  Created on: Jan 31, 2017
 *      Author: goguma
 */
#include "threadtest.h"
#include "networktest.h"

static connection_h connection;

static Eina_Bool
_check_network_connection(appdata_s *ad)
{
	int error_code;

	/* Create a connection handle */
	error_code = connection_create(&connection);
	if (error_code != CONNECTION_ERROR_NONE)
		return EINA_FALSE;

	/*
	       Get the type of the current profile for data connection
	       net_state is the network type defined in the connection_type_e enumerator
	 */
	connection_type_e net_state;
	error_code = connection_get_type(connection, &net_state);
	if (error_code == CONNECTION_ERROR_NONE) {
		dlog_print(DLOG_INFO, LOG_TAG, "Network connection type: %d", net_state);
		ad->network.network_connected = EINA_TRUE;
		ad->network.network = net_state;
	}

	return EINA_TRUE;
}

void
_initialize_network(void *data, Ecore_Thread *thread)
{

	appdata_s *ad = (appdata_s *)data;
	if (ad->network.network_connected == EINA_FALSE)
	{
		/*try to connect network*/
		_check_network_connection(ad);
	}
	ecore_main_loop_thread_safe_call_async(_set_label_text_network_update, data);

}
