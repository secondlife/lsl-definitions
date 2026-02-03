class LLScriptFinalDamageEvent : public LLScriptEvent
{
public:
    LLScriptFinalDamageEvent(S32 line, S32 col, LLScriptIdentifier *count)
        : LLScriptEvent(line, col, LSTT_FINAL_DAMAGE)
        , mCount(count)
    {
    }

    ~LLScriptFinalDamageEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mCount;
};

class LLScriptGameControlEvent : public LLScriptEvent
{
public:
    LLScriptGameControlEvent(S32 line, S32 col, LLScriptIdentifier *id, LLScriptIdentifier *buttons, LLScriptIdentifier *axes)
        : LLScriptEvent(line, col, LSTT_GAME_CONTROL)
        , mId(id)
        , mButtons(buttons)
        , mAxes(axes)
    {
    }

    ~LLScriptGameControlEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mId;
    LLScriptIdentifier *mButtons;
    LLScriptIdentifier *mAxes;
};

class LLScriptOnDamageEvent : public LLScriptEvent
{
public:
    LLScriptOnDamageEvent(S32 line, S32 col, LLScriptIdentifier *count)
        : LLScriptEvent(line, col, LSTT_ON_DAMAGE)
        , mCount(count)
    {
    }

    ~LLScriptOnDamageEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mCount;
};

class LLScriptOnDeathEvent : public LLScriptEvent
{
public:
    LLScriptOnDeathEvent(S32 line, S32 col)
        : LLScriptEvent(line, col, LSTT_ON_DEATH)

    {
    }

    ~LLScriptOnDeathEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();


};

class LLScriptStateEntryEvent : public LLScriptEvent
{
public:
    LLScriptStateEntryEvent(S32 line, S32 col)
        : LLScriptEvent(line, col, LSTT_STATE_ENTRY)

    {
    }

    ~LLScriptStateEntryEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();


};

