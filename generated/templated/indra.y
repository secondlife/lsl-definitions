/* Minimal parser template for generated output */
/* ONLY for testing, this will not compile! */

%{
/* Prologue */
%}


%token    AT_ROT_TARGET
%token    AT_TARGET
%token    ATTACH
%token    COLLISION
%token    COLLISION_END
%token    COLLISION_START
%token    CONTROL
%token    DATASERVER
%token    EMAIL
%token    EXPERIENCE_PERMISSIONS
%token    EXPERIENCE_PERMISSIONS_DENIED
%token    FINAL_DAMAGE
%token    GAME_CONTROL
%token    HTTP_REQUEST
%token    HTTP_RESPONSE
%token    LAND_COLLISION
%token    LAND_COLLISION_END
%token    LAND_COLLISION_START
%token    LINK_MESSAGE
%token    MONEY
%token    MOVING_END
%token    MOVING_START
%token    NO_SENSOR
%token    NOT_AT_ROT_TARGET
%token    NOT_AT_TARGET
%token    OBJECT_REZ
%token    ON_DAMAGE
%token    ON_DEATH
%token    PATH_UPDATE
%token    REMOTE_DATA
%token    RUN_TIME_PERMISSIONS
%token    SENSOR
%token    STATE_ENTRY
%token    STATE_EXIT
%token    TIMER
%token    TOUCH
%token    TOUCH_END
%token    TOUCH_START
%token    TRANSACTION_RESULT




%type<event>    at_rot_target
%type<event>    at_target
%type<event>    attach
%type<event>    collision
%type<event>    collision_end
%type<event>    collision_start
%type<event>    control
%type<event>    dataserver
%type<event>    email
%type<event>    experience_permissions
%type<event>    experience_permissions_denied
%type<event>    final_damage
%type<event>    game_control
%type<event>    http_request
%type<event>    http_response
%type<event>    land_collision
%type<event>    land_collision_end
%type<event>    land_collision_start
%type<event>    link_message
%type<event>    money
%type<event>    moving_end
%type<event>    moving_start
%type<event>    no_sensor
%type<event>    not_at_rot_target
%type<event>    not_at_target
%type<event>    object_rez
%type<event>    on_damage
%type<event>    on_death
%type<event>    path_update
%type<event>    remote_data
%type<event>    run_time_permissions
%type<event>    sensor
%type<event>    state_entry
%type<event>    state_exit
%type<event>    timer
%type<event>    touch
%type<event>    touch_end
%type<event>    touch_start
%type<event>    transaction_result



%%



    | at_rot_target compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | at_target compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | attach compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | collision compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | collision_end compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | collision_start compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | control compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | dataserver compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | email compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | experience_permissions compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | experience_permissions_denied compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | final_damage compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | game_control compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | http_request compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | http_response compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | land_collision compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | land_collision_end compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | land_collision_start compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | link_message compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | money compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | moving_end compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | moving_start compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | no_sensor compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | not_at_rot_target compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | not_at_target compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | object_rez compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | on_damage compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | on_death compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | path_update compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | remote_data compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | run_time_permissions compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | sensor compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | state_entry compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | state_exit compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | timer compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | touch compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | touch_end compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | touch_start compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }

    | transaction_result compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }




attach
    : ATTACH '(' LLKEY IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptAttachEvent(gLine, gColumn, id0);
    }
    ;

collision
    : COLLISION '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptCollisionEvent(gLine, gColumn, id0);
    }
    ;

collision_end
    : COLLISION_END '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptCollisionEndEvent(gLine, gColumn, id0);
    }
    ;

collision_start
    : COLLISION_START '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptCollisionStartEvent(gLine, gColumn, id0);
    }
    ;

control
    : CONTROL '(' LLKEY IDENTIFIER  ',' INTEGER IDENTIFIER  ',' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);
        $$ = new LLScriptControlEvent(gLine, gColumn, id0, id1, id2);
    }
    ;

dataserver
    : DATASERVER '(' LLKEY IDENTIFIER  ',' STRING IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);
        $$ = new LLScriptDataserverEvent(gLine, gColumn, id0, id1);
    }
    ;

email
    : EMAIL '(' STRING IDENTIFIER  ',' STRING IDENTIFIER  ',' STRING IDENTIFIER  ',' STRING IDENTIFIER  ',' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);

        LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, $13);
        gAllocationManager->addAllocation(id3);

        LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, $16);
        gAllocationManager->addAllocation(id4);
        $$ = new LLScriptEmailEvent(gLine, gColumn, id0, id1, id2, id3, id4);
    }
    ;

final_damage
    : FINAL_DAMAGE '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptFinalDamageEvent(gLine, gColumn, id0);
    }
    ;

game_control
    : GAME_CONTROL '(' LLKEY IDENTIFIER  ',' INTEGER IDENTIFIER  ',' LIST IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);
        $$ = new LLScriptGameControlEvent(gLine, gColumn, id0, id1, id2);
    }
    ;

http_request
    : HTTP_REQUEST '(' LLKEY IDENTIFIER  ',' STRING IDENTIFIER  ',' STRING IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);
        $$ = new LLScriptHTTPRequestEvent(gLine, gColumn, id0, id1, id2);
    }
    ;

http_response
    : HTTP_RESPONSE '(' LLKEY IDENTIFIER  ',' INTEGER IDENTIFIER  ',' LIST IDENTIFIER  ',' STRING IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);

        LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, $13);
        gAllocationManager->addAllocation(id3);
        $$ = new LLScriptHTTPResponseEvent(gLine, gColumn, id0, id1, id2, id3);
    }
    ;

land_collision
    : LAND_COLLISION '(' VECTOR IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptLandCollisionEvent(gLine, gColumn, id0);
    }
    ;

land_collision_end
    : LAND_COLLISION_END '(' VECTOR IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptLandCollisionEndEvent(gLine, gColumn, id0);
    }
    ;

land_collision_start
    : LAND_COLLISION_START '(' VECTOR IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptLandCollisionStartEvent(gLine, gColumn, id0);
    }
    ;

link_message
    : LINK_MESSAGE '(' INTEGER IDENTIFIER  ',' INTEGER IDENTIFIER  ',' STRING IDENTIFIER  ',' LLKEY IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);

        LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, $13);
        gAllocationManager->addAllocation(id3);
        $$ = new LLScriptLinkMessageEvent(gLine, gColumn, id0, id1, id2, id3);
    }
    ;

money
    : MONEY '(' LLKEY IDENTIFIER  ',' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);
        $$ = new LLScriptMoneyEvent(gLine, gColumn, id0, id1);
    }
    ;

moving_end
    : MOVING_END '('  ')'
    {
        $$ = new LLScriptMovingEndEvent(gLine, gColumn);
    }
    ;

moving_start
    : MOVING_START '('  ')'
    {
        $$ = new LLScriptMovingStartEvent(gLine, gColumn);
    }
    ;

no_sensor
    : NO_SENSOR '('  ')'
    {
        $$ = new LLScriptNoSensorEvent(gLine, gColumn);
    }
    ;

object_rez
    : OBJECT_REZ '(' LLKEY IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptObjectRezEvent(gLine, gColumn, id0);
    }
    ;

on_damage
    : ON_DAMAGE '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptOnDamageEvent(gLine, gColumn, id0);
    }
    ;

on_death
    : ON_DEATH '('  ')'
    {
        $$ = new LLScriptOnDeathEvent(gLine, gColumn);
    }
    ;

path_update
    : PATH_UPDATE '(' INTEGER IDENTIFIER  ',' LIST IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);
        $$ = new LLScriptPathUpdateEvent(gLine, gColumn, id0, id1);
    }
    ;

sensor
    : SENSOR '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptSensorEvent(gLine, gColumn, id0);
    }
    ;

state_entry
    : STATE_ENTRY '('  ')'
    {
        $$ = new LLScriptStateEntryEvent(gLine, gColumn);
    }
    ;

state_exit
    : STATE_EXIT '('  ')'
    {
        $$ = new LLScriptStateExitEvent(gLine, gColumn);
    }
    ;

timer
    : TIMER '('  ')'
    {
        $$ = new LLScriptTimerEvent(gLine, gColumn);
    }
    ;

touch
    : TOUCH '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptTouchEvent(gLine, gColumn, id0);
    }
    ;

touch_end
    : TOUCH_END '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptTouchEndEvent(gLine, gColumn, id0);
    }
    ;

touch_start
    : TOUCH_START '(' INTEGER IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);
        $$ = new LLScriptTouchStartEvent(gLine, gColumn, id0);
    }
    ;

transaction_result
    : TRANSACTION_RESULT '(' LLKEY IDENTIFIER  ',' INTEGER IDENTIFIER  ',' STRING IDENTIFIER  ')'
    {

        LLScriptIdentifier	*id0 = new LLScriptIdentifier(gLine, gColumn, $4);
        gAllocationManager->addAllocation(id0);

        LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, $7);
        gAllocationManager->addAllocation(id1);

        LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, $10);
        gAllocationManager->addAllocation(id2);
        $$ = new LLScriptTransactionResultEvent(gLine, gColumn, id0, id1, id2);
    }
    ;




%%
