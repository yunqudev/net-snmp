/*
 * This file was generated by mib2c and is intended for use as
 * a mib module for the ucd-snmp snmpd agent. 
 */


/*
 * This should always be included first before anything else 
 */
#include <net-snmp/net-snmp-config.h>

#include <sys/types.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif


/*
 * minimal include directives 
 */
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "header_complex.h"
#include "snmpNotifyFilterProfileTable.h"

#ifndef NETSNMP_NO_WRITE_SUPPORT
netsnmp_feature_require(header_complex_find_entry)
#endif /* NETSNMP_NO_WRITE_SUPPORT */

/*
 * snmpNotifyFilterProfileTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */


oid             snmpNotifyFilterProfileTable_variables_oid[] =
    { 1, 3, 6, 1, 6, 3, 13, 1, 2 };


/*
 * variable2 snmpNotifyFilterProfileTable_variables:
 *   this variable defines function callbacks and type return information 
 *   for the snmpNotifyFilterProfileTable mib section 
 */


struct variable2 snmpNotifyFilterProfileTable_variables[] = {
    /*
     * magic number        , variable type , ro/rw , callback fn  , L, oidsuffix 
     */
#define   SNMPNOTIFYFILTERPROFILENAME  3
    {SNMPNOTIFYFILTERPROFILENAME, ASN_OCTET_STR, NETSNMP_OLDAPI_RWRITE,
     var_snmpNotifyFilterProfileTable, 2, {1, 1}},
#define   SNMPNOTIFYFILTERPROFILESTORTYPE  4
    {SNMPNOTIFYFILTERPROFILESTORTYPE, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_snmpNotifyFilterProfileTable, 2, {1, 2}},
#define   SNMPNOTIFYFILTERPROFILEROWSTATUS  5
    {SNMPNOTIFYFILTERPROFILEROWSTATUS, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_snmpNotifyFilterProfileTable, 2, {1, 3}},

};
/*
 * (L = length of the oidsuffix) 
 */


/*
 * global storage of our data, saved in and configured by header_complex() 
 */
static struct header_complex_index *snmpNotifyFilterProfileTableStorage =
    NULL;




/*
 * init_snmpNotifyFilterProfileTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void
init_snmpNotifyFilterProfileTable(void)
{
    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "initializing...  "));


    /*
     * register ourselves with the agent to handle our mib tree 
     */
    REGISTER_MIB("snmpNotifyFilterProfileTable",
                 snmpNotifyFilterProfileTable_variables, variable2,
                 snmpNotifyFilterProfileTable_variables_oid);


    /*
     * register our config handler(s) to deal with registrations 
     */
    snmpd_register_config_handler("snmpNotifyFilterProfileTable",
                                  parse_snmpNotifyFilterProfileTable, NULL,
                                  NULL);




    /*
     * we need to be called back later to store our data 
     */
    snmp_register_callback(SNMP_CALLBACK_LIBRARY, SNMP_CALLBACK_STORE_DATA,
                           store_snmpNotifyFilterProfileTable, NULL);


    /*
     * place any other initialization junk you need here 
     */


    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "done.\n"));
}


/*
 * snmpNotifyFilterProfileTable_add(): adds a structure node to our data set 
 */
int
snmpNotifyFilterProfileTable_add(struct snmpNotifyFilterProfileTable_data
                                 *thedata)
{
    netsnmp_variable_list *vars = NULL;
    int retVal;

    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "adding data...  "));
    /*
     * add the index variables to the varbind list, which is 
     * used by header_complex to index the data 
     */

    snmp_varlist_add_variable(&vars, NULL, 0, ASN_PRIV_IMPLIED_OCTET_STR,
                              (u_char *) thedata->snmpTargetParamsName,
                              thedata->snmpTargetParamsNameLen);

    if (header_complex_maybe_add_data(&snmpNotifyFilterProfileTableStorage, vars,
                                      thedata, 1) != NULL){
       DEBUGMSGTL(("snmpNotifyFilterProfileTable", "registered an entry\n"));
       retVal = SNMPERR_SUCCESS;
    }else{
       retVal = SNMPERR_GENERR;  	
    }


    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "done.\n"));
    return retVal;
}


/*
 * parse_snmpNotifyFilterProfileTable():
 *   parses .conf file entries needed to configure the mib.
 */
void
parse_snmpNotifyFilterProfileTable(const char *token, char *line)
{
    size_t          tmpint;
    struct snmpNotifyFilterProfileTable_data *StorageTmp =
        SNMP_MALLOC_STRUCT(snmpNotifyFilterProfileTable_data);

    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "parsing config...  "));

    if (StorageTmp == NULL) {
        config_perror("malloc failure");
        return;
    }

    line =
        read_config_read_data(ASN_OCTET_STR, line,
                              &StorageTmp->snmpTargetParamsName,
                              &StorageTmp->snmpTargetParamsNameLen);
    if (StorageTmp->snmpTargetParamsName == NULL) {
        config_perror("invalid specification for snmpTargetParamsName");
        return;
    }

    line =
        read_config_read_data(ASN_OCTET_STR, line,
                              &StorageTmp->snmpNotifyFilterProfileName,
                              &StorageTmp->snmpNotifyFilterProfileNameLen);
    if (StorageTmp->snmpNotifyFilterProfileName == NULL) {
        config_perror("invalid specification for snmpNotifyFilterProfileName");
        SNMP_FREE(StorageTmp);
        return;
    }

    line =
        read_config_read_data(ASN_INTEGER, line,
                              &StorageTmp->snmpNotifyFilterProfileStorType,
                              &tmpint);

    line =
        read_config_read_data(ASN_INTEGER, line,
                              &StorageTmp->
                              snmpNotifyFilterProfileRowStatus, &tmpint);

    if (snmpNotifyFilterProfileTable_add(StorageTmp) != SNMPERR_SUCCESS){
        SNMP_FREE(StorageTmp->snmpTargetParamsName);
        SNMP_FREE(StorageTmp->snmpNotifyFilterProfileName);
        SNMP_FREE(StorageTmp);
    }

    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "done.\n"));
}




/*
 * store_snmpNotifyFilterProfileTable():
 *   stores .conf file entries needed to configure the mib.
 */
int
store_snmpNotifyFilterProfileTable(int majorID, int minorID,
                                   void *serverarg, void *clientarg)
{
    char            line[SNMP_MAXBUF];
    char           *cptr;
    struct snmpNotifyFilterProfileTable_data *StorageTmp;
    struct header_complex_index *hcindex;


    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "storing data...  "));

    for (hcindex = snmpNotifyFilterProfileTableStorage; hcindex != NULL;
         hcindex = hcindex->next) {
        StorageTmp =
            (struct snmpNotifyFilterProfileTable_data *) hcindex->data;

        if ((StorageTmp->snmpNotifyFilterProfileStorType == ST_NONVOLATILE) ||
            (StorageTmp->snmpNotifyFilterProfileStorType == ST_PERMANENT)) {

            memset(line, 0, sizeof(line));
            strcat(line, "snmpNotifyFilterProfileTable ");
            cptr = line + strlen(line);

            cptr =
                read_config_store_data(ASN_OCTET_STR, cptr,
                                       &StorageTmp->snmpTargetParamsName,
                                       &StorageTmp->
                                       snmpTargetParamsNameLen);
            cptr =
                read_config_store_data(ASN_OCTET_STR, cptr,
                                       &StorageTmp->
                                       snmpNotifyFilterProfileName,
                                       &StorageTmp->
                                       snmpNotifyFilterProfileNameLen);
            cptr =
                read_config_store_data(ASN_INTEGER, cptr,
                                       &StorageTmp->
                                       snmpNotifyFilterProfileStorType,
                                       NULL);
            cptr =
                read_config_store_data(ASN_INTEGER, cptr,
                                       &StorageTmp->
                                       snmpNotifyFilterProfileRowStatus,
                                       NULL);

            snmpd_store_config(line);
        }
    }
    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "done.\n"));
    return 0;
}




/*
 * var_snmpNotifyFilterProfileTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_snmpNotifyFilterProfileTable above.
 */
unsigned char  *
var_snmpNotifyFilterProfileTable(struct variable *vp,
                                 oid * name,
                                 size_t * length,
                                 int exact,
                                 size_t * var_len,
                                 WriteMethod ** write_method)
{


    struct snmpNotifyFilterProfileTable_data *StorageTmp = NULL;
    int found = 1;


    DEBUGMSGTL(("snmpNotifyFilterProfileTable",
                "var_snmpNotifyFilterProfileTable: Entering...  \n"));
    /*
     * this assumes you have registered all your data properly
     */
    if ((StorageTmp = (struct snmpNotifyFilterProfileTable_data *)
         header_complex((struct header_complex_index *)
                        snmpNotifyFilterProfileTableStorage, vp, name,
                        length, exact, var_len, write_method)) == NULL) {
        found = 0;
    }

    switch (vp->magic) {
#ifndef NETSNMP_NO_WRITE_SUPPORT
    case SNMPNOTIFYFILTERPROFILENAME:
        *write_method = write_snmpNotifyFilterProfileName;
        break;

    case SNMPNOTIFYFILTERPROFILESTORTYPE:
        *write_method = write_snmpNotifyFilterProfileStorType;
        break;

    case SNMPNOTIFYFILTERPROFILEROWSTATUS:
        *write_method = write_snmpNotifyFilterProfileRowStatus;
        break;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */
    default:
        *write_method = NULL;
    }

    if (!found) {
        return NULL;
    }

    /*
     * this is where we do the value assignments for the mib results.
     */
    switch (vp->magic) {

    case SNMPNOTIFYFILTERPROFILENAME:
        *var_len = StorageTmp->snmpNotifyFilterProfileNameLen;
        return (u_char *) StorageTmp->snmpNotifyFilterProfileName;

    case SNMPNOTIFYFILTERPROFILESTORTYPE:
        *var_len = sizeof(StorageTmp->snmpNotifyFilterProfileStorType);
        return (u_char *) & StorageTmp->snmpNotifyFilterProfileStorType;

    case SNMPNOTIFYFILTERPROFILEROWSTATUS:
        *var_len = sizeof(StorageTmp->snmpNotifyFilterProfileRowStatus);
        return (u_char *) & StorageTmp->snmpNotifyFilterProfileRowStatus;


    default:
        ERROR_MSG("");
    }

    return NULL;
}



static struct snmpNotifyFilterProfileTable_data *StorageNew;

#ifndef NETSNMP_NO_WRITE_SUPPORT 

int
write_snmpNotifyFilterProfileName(int action,
                                  u_char * var_val,
                                  u_char var_val_type,
                                  size_t var_val_len,
                                  u_char * statP,
                                  oid * name, size_t name_len)
{
    static char    *tmpvar;
    struct snmpNotifyFilterProfileTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len -
        (sizeof(snmpNotifyFilterProfileTable_variables_oid) / sizeof(oid) +
         3 - 1);


    DEBUGMSGTL(("snmpNotifyFilterProfileTable",
                "write_snmpNotifyFilterProfileName entering action=%d...  \n",
                action));
    if (action != RESERVE1 &&
        (StorageTmp = (struct snmpNotifyFilterProfileTable_data *)
         header_complex((struct header_complex_index *)
                        snmpNotifyFilterProfileTableStorage, NULL,
                        &name[sizeof
                              (snmpNotifyFilterProfileTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL) {
        if ((StorageTmp = StorageNew) == NULL)
            return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */
    }


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OCTET_STR) {
            return SNMP_ERR_WRONGTYPE;
        }
        if (var_val_len < 1 || var_val_len > 32) {
            return SNMP_ERR_WRONGLENGTH;
        }
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        tmpvar = StorageTmp->snmpNotifyFilterProfileName;
        tmplen = StorageTmp->snmpNotifyFilterProfileNameLen;
        StorageTmp->snmpNotifyFilterProfileName = (char*)calloc(1, var_val_len + 1);
        if (NULL == StorageTmp->snmpNotifyFilterProfileName)
            return SNMP_ERR_RESOURCEUNAVAILABLE;
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in string for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        memcpy(StorageTmp->snmpNotifyFilterProfileName, var_val, var_val_len);
        StorageTmp->snmpNotifyFilterProfileNameLen = var_val_len;
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->snmpNotifyFilterProfileName);
        StorageTmp->snmpNotifyFilterProfileName = tmpvar;
        StorageTmp->snmpNotifyFilterProfileNameLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);
        snmp_store_needed(NULL);
        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_snmpNotifyFilterProfileStorType(int action,
                                      u_char * var_val,
                                      u_char var_val_type,
                                      size_t var_val_len,
                                      u_char * statP,
                                      oid * name, size_t name_len)
{
    static int      tmpvar;
    long            value = *((long *) var_val);
    struct snmpNotifyFilterProfileTable_data *StorageTmp = NULL;
    size_t          newlen =
        name_len -
        (sizeof(snmpNotifyFilterProfileTable_variables_oid) / sizeof(oid) +
         3 - 1);


    DEBUGMSGTL(("snmpNotifyFilterProfileTable",
                "write_snmpNotifyFilterProfileStorType entering action=%d...  \n",
                action));
    if (action != RESERVE1 &&
        (StorageTmp = (struct snmpNotifyFilterProfileTable_data *)
         header_complex((struct header_complex_index *)
                        snmpNotifyFilterProfileTableStorage, NULL,
                        &name[sizeof
                              (snmpNotifyFilterProfileTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL) {
        if ((StorageTmp = StorageNew) == NULL)
            return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */
    }

    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER) {
            return SNMP_ERR_WRONGTYPE;
        }
        if (var_val_len != sizeof(long)) {
            return SNMP_ERR_WRONGLENGTH;
        }
        if (value != SNMP_STORAGE_OTHER && value != SNMP_STORAGE_VOLATILE
            && value != SNMP_STORAGE_NONVOLATILE) {
            return SNMP_ERR_WRONGVALUE;
        }
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in long_ret for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->snmpNotifyFilterProfileStorType;
        StorageTmp->snmpNotifyFilterProfileStorType = *((long *) var_val);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        StorageTmp->snmpNotifyFilterProfileStorType = tmpvar;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        snmp_store_needed(NULL);
        break;
    }
    return SNMP_ERR_NOERROR;
}






int
write_snmpNotifyFilterProfileRowStatus(int action,
                                       u_char * var_val,
                                       u_char var_val_type,
                                       size_t var_val_len,
                                       u_char * statP,
                                       oid * name, size_t name_len)
{
    struct snmpNotifyFilterProfileTable_data *StorageTmp = NULL;
    static struct snmpNotifyFilterProfileTable_data *StorageDel;
    size_t          newlen =
        name_len -
        (sizeof(snmpNotifyFilterProfileTable_variables_oid) / sizeof(oid) +
         3 - 1);
    static int      old_value;
    int             set_value = *((long *) var_val);
    netsnmp_variable_list *vars;
    struct header_complex_index *hciptr;


    DEBUGMSGTL(("snmpNotifyFilterProfileTable",
                "write_snmpNotifyFilterProfileRowStatus entering action=%d...  \n",
                action));
    StorageTmp = (struct snmpNotifyFilterProfileTable_data *)
        header_complex((struct header_complex_index *)
                       snmpNotifyFilterProfileTableStorage, NULL,
                       &name[sizeof
                             (snmpNotifyFilterProfileTable_variables_oid) /
                             sizeof(oid) + 3 - 1], &newlen, 1, NULL, NULL);

    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER || var_val == NULL) {
            return SNMP_ERR_WRONGTYPE;
        }
        if (var_val_len != sizeof(long)) {
            return SNMP_ERR_WRONGLENGTH;
        }
        if (set_value < 1 || set_value > 6 || set_value == RS_NOTREADY) {
            return SNMP_ERR_WRONGVALUE;
        }
        /*
         * stage one: test validity 
         */
        if (StorageTmp == NULL) {
            /*
             * create the row now? 
             */


            /*
             * ditch illegal values now 
             */
            if (set_value == RS_ACTIVE || set_value == RS_NOTINSERVICE) {
                return SNMP_ERR_INCONSISTENTVALUE;
            }
        } else {
            /*
             * row exists.  Check for a valid state change 
             */
            if (set_value == RS_CREATEANDGO
                || set_value == RS_CREATEANDWAIT) {
                /*
                 * can't create a row that exists 
                 */
                return SNMP_ERR_INCONSISTENTVALUE;
            }
            if ((set_value == RS_ACTIVE || set_value == RS_NOTINSERVICE) &&
                StorageTmp->snmpNotifyFilterProfileNameLen == 0) {
                /*
                 * can't activate row without a profile name
                 */
                return SNMP_ERR_INCONSISTENTVALUE;
            }
            /*
             * XXX: interaction with row storage type needed 
             */
        }

        /*
         * memory reseveration, final preparation... 
         */
        if (StorageTmp == NULL &&
            (set_value == RS_CREATEANDGO
             || set_value == RS_CREATEANDWAIT)) {
            /*
             * creation 
             */
            vars = NULL;

            snmp_varlist_add_variable(&vars, NULL, 0,
                                      ASN_PRIV_IMPLIED_OCTET_STR, NULL, 0);

            if (header_complex_parse_oid
                (&
                 (name
                  [sizeof(snmpNotifyFilterProfileTable_variables_oid) /
                   sizeof(oid) + 2]), newlen, vars) != SNMPERR_SUCCESS) {
                snmp_free_var(vars);
                return SNMP_ERR_INCONSISTENTNAME;
            }

            StorageNew =
                SNMP_MALLOC_STRUCT(snmpNotifyFilterProfileTable_data);
            if (StorageNew == NULL)
                return SNMP_ERR_GENERR;
            memdup((u_char **) & (StorageNew->snmpTargetParamsName),
                   vars->val.string, vars->val_len);
            StorageNew->snmpTargetParamsNameLen = vars->val_len;
            StorageNew->snmpNotifyFilterProfileStorType = ST_NONVOLATILE;

            StorageNew->snmpNotifyFilterProfileRowStatus = RS_NOTREADY;
            snmp_free_var(vars);
        }


        break;

    case RESERVE2:
        break;

    case FREE:
        /*
         * XXX: free, zero vars 
         */
        /*
         * Release any resources that have been allocated 
         */
        if (StorageNew != NULL) {
            SNMP_FREE(StorageNew->snmpTargetParamsName);
            SNMP_FREE(StorageNew->snmpNotifyFilterProfileName);
            free(StorageNew);
            StorageNew = NULL;
        }
        break;




    case ACTION:
        /*
         * The variable has been stored in set_value for you to
         * use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in
         * the UNDO case 
         */

        if (StorageTmp == NULL &&
            (set_value == RS_CREATEANDGO ||
             set_value == RS_CREATEANDWAIT)) {
            /*
             * row creation, so add it 
             */
            if (StorageNew != NULL)
                snmpNotifyFilterProfileTable_add(StorageNew);
            /*
             * XXX: ack, and if it is NULL? 
             */
        } else if (set_value != RS_DESTROY) {
            /*
             * set the flag? 
             */
            if (StorageTmp == NULL)
                return SNMP_ERR_GENERR; /* should never ever get here */
            
            old_value = StorageTmp->snmpNotifyFilterProfileRowStatus;
            StorageTmp->snmpNotifyFilterProfileRowStatus =
                *((long *) var_val);
        } else {
            /*
             * destroy...  extract it for now 
             */
            if (StorageTmp) {
                hciptr =
                    header_complex_find_entry
                    (snmpNotifyFilterProfileTableStorage, StorageTmp);
                StorageDel = (struct snmpNotifyFilterProfileTable_data *)
                    header_complex_extract_entry((struct
                                                  header_complex_index **)
                                                 &snmpNotifyFilterProfileTableStorage,
                                                 hciptr);
            }

        }
        break;

    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        if (StorageTmp == NULL &&
            (set_value == RS_CREATEANDGO ||
             set_value == RS_CREATEANDWAIT)) {
            /*
             * row creation, so remove it again 
             */
            hciptr =
                header_complex_find_entry
                (snmpNotifyFilterProfileTableStorage, StorageNew);
            StorageDel = (struct snmpNotifyFilterProfileTable_data *)
                header_complex_extract_entry((struct header_complex_index
                                              **)
                                             &snmpNotifyFilterProfileTableStorage,
                                             hciptr);
            /*
             * XXX: free it 
             */
        } else if (StorageDel != NULL) {
            /*
             * row deletion, so add it again 
             */
            snmpNotifyFilterProfileTable_add(StorageDel);
            StorageDel = NULL;
        } else if (set_value != RS_DESTROY) {
            if (StorageTmp)
                StorageTmp->snmpNotifyFilterProfileRowStatus = old_value;
        }
        break;




    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        if (StorageDel != NULL) {
            SNMP_FREE(StorageDel->snmpTargetParamsName);
            SNMP_FREE(StorageDel->snmpNotifyFilterProfileName);
            free(StorageDel);
            StorageDel = NULL;
        }
        if (StorageTmp && set_value == RS_CREATEANDGO) {
            if (StorageTmp->snmpNotifyFilterProfileNameLen)
                StorageTmp->snmpNotifyFilterProfileRowStatus = RS_ACTIVE;
            StorageNew = NULL;
        } else if (StorageTmp && set_value == RS_CREATEANDWAIT) {
            if (StorageTmp->snmpNotifyFilterProfileNameLen)
                StorageTmp->snmpNotifyFilterProfileRowStatus = RS_NOTINSERVICE;
            StorageNew = NULL;
        }
        snmp_store_needed(NULL);
        break;
    }
    return SNMP_ERR_NOERROR;
}


#endif /* !NETSNMP_NO_WRITE_SUPPORT */ 


char           *
get_FilterProfileName(const char *paramName, size_t paramName_len,
               size_t * profileName_len)
{
    netsnmp_variable_list *vars = NULL;
    struct snmpNotifyFilterProfileTable_data *data;

    /*
     * put requested info into var structure 
     */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_PRIV_IMPLIED_OCTET_STR,
                              (const u_char *) paramName, paramName_len);

    /*
     * get the data from the header_complex storage 
     */
    data = (struct snmpNotifyFilterProfileTable_data *)
        header_complex_get(snmpNotifyFilterProfileTableStorage, vars);

    /*
     * free search index 
     */
    snmp_free_var(vars);

    /*
     * return the requested information (if this row is active) 
     */
    if (data && data->snmpNotifyFilterProfileRowStatus == RS_ACTIVE) {
        *profileName_len = data->snmpNotifyFilterProfileNameLen;
        return data->snmpNotifyFilterProfileName;
    }

    *profileName_len = 0;
    return NULL;
}
