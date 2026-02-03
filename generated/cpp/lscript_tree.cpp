
void LLScriptFinalDamageEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "final_damage( ");
        fprintf(fp, "integer ");
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);

        fprintf(fp, " )\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "final_damage");

        if (scope->checkEntry(mCount->mName))
        {
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }
        else
        {
            mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
        }

        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (mCount->mScopeEntry)
            {
                mCount->mScopeEntry->mOffset = (S32)count;
                mCount->mScopeEntry->mSize = 4;
                count += mCount->mScopeEntry->mSize;

            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "final_damage";
            chunk->addBytes(name, strlen(name) + 1);
            chunk->addBytes(mCount->mName, strlen(mCount->mName) + 1);

#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "final_damage(");
        fprintf(fp, " ");
        fprintf(fp, "int32 ");
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, " ");

        fprintf(fp, ")");
        break;
    default:
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);;
        break;
    }
}

S32 LLScriptFinalDamageEvent::getSize()
{
    return 4;
}

void LLScriptGameControlEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "game_control( ");
        fprintf(fp, "key ");
        mId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, ", integer ");
        mButtons->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, ", list ");
        mAxes->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);

        fprintf(fp, " )\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "game_control");

        if (scope->checkEntry(mId->mName))
        {
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }
        else
        {
            mId->mScopeEntry = scope->addEntry(mId->mName, LIT_VARIABLE, LST_KEY);
        }

        if (scope->checkEntry(mButtons->mName))
        {
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }
        else
        {
            mButtons->mScopeEntry = scope->addEntry(mButtons->mName, LIT_VARIABLE, LST_INTEGER);
        }

        if (scope->checkEntry(mAxes->mName))
        {
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }
        else
        {
            mAxes->mScopeEntry = scope->addEntry(mAxes->mName, LIT_VARIABLE, LST_LIST);
        }

        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (mId->mScopeEntry)
            {
                mId->mScopeEntry->mOffset = (S32)count;
                mId->mScopeEntry->mSize = 4;
                count += mId->mScopeEntry->mSize;
                mButtons->mScopeEntry->mOffset = (S32)count;
                mButtons->mScopeEntry->mSize = 4;
                count += mButtons->mScopeEntry->mSize;
                mAxes->mScopeEntry->mOffset = (S32)count;
                mAxes->mScopeEntry->mSize = 4;
                count += mAxes->mScopeEntry->mSize;

            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "game_control";
            chunk->addBytes(name, strlen(name) + 1);
            chunk->addBytes(mId->mName, strlen(mId->mName) + 1);
            chunk->addBytes(mButtons->mName, strlen(mButtons->mName) + 1);
            chunk->addBytes(mAxes->mName, strlen(mAxes->mName) + 1);

#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "game_control(");
        fprintf(fp, " ");
        fprintf(fp, "valuetype [ScriptTypes]LindenLab.SecondLife.Key ");
        mId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, ", int32 ");
        mButtons->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, ", class [mscorlib]System.Collections.ArrayList ");
        mAxes->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, " ");

        fprintf(fp, ")");
        break;
    default:
        mId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);;
        mButtons->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);;
        mAxes->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);;
        break;
    }
}

S32 LLScriptGameControlEvent::getSize()
{
    return 12;
}

void LLScriptOnDamageEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "on_damage( ");
        fprintf(fp, "integer ");
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);

        fprintf(fp, " )\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "on_damage");

        if (scope->checkEntry(mCount->mName))
        {
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }
        else
        {
            mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
        }

        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (mCount->mScopeEntry)
            {
                mCount->mScopeEntry->mOffset = (S32)count;
                mCount->mScopeEntry->mSize = 4;
                count += mCount->mScopeEntry->mSize;

            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "on_damage";
            chunk->addBytes(name, strlen(name) + 1);
            chunk->addBytes(mCount->mName, strlen(mCount->mName) + 1);

#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "on_damage(");
        fprintf(fp, " ");
        fprintf(fp, "int32 ");
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
        fprintf(fp, " ");

        fprintf(fp, ")");
        break;
    default:
        mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);;
        break;
    }
}

S32 LLScriptOnDamageEvent::getSize()
{
    return 4;
}

void LLScriptOnDeathEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "on_death( ");

        fprintf(fp, " )\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "on_death");

        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (false)
            {

            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "on_death";
            chunk->addBytes(name, strlen(name) + 1);

#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "on_death(");

        fprintf(fp, ")");
        break;
    default:

        break;
    }
}

S32 LLScriptOnDeathEvent::getSize()
{
    return 0;
}

void LLScriptStateEntryEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "state_entry( ");

        fprintf(fp, " )\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "state_entry");

        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (false)
            {

            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "state_entry";
            chunk->addBytes(name, strlen(name) + 1);

#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "state_entry(");

        fprintf(fp, ")");
        break;
    default:

        break;
    }
}

S32 LLScriptStateEntryEvent::getSize()
{
    return 0;
}
