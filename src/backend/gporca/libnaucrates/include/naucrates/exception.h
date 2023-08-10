//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 EMC Corp.
//
//	@filename:
//		exception.h
//
//	@doc:
//		Definition of DXL-specific exception types
//---------------------------------------------------------------------------
#ifndef DXL_exception_H
#define DXL_exception_H

#include "gpos/memory/CMemoryPool.h"
#include "gpos/types.h"

namespace gpdxl
{
// major exception types - reserve range 200-1000
enum ExMajor
{
	ExmaDXL = 200,
	ExmaMD = 300,
	ExmaComm = 400,
	ExmaGPDB = 500,
	ExmaConstExprEval = 600,

	ExmaSentinel
};

// minor exception types
enum ExMinor
{
	// DXL-parsing related errors
	ExmiDXLUnexpectedTag,
	ExmiDXLMissingAttribute,
	ExmiDXLInvalidAttributeValue,
	ExmiDXLUnrecognizedOperator,
	ExmiDXLUnrecognizedType,
	ExmiDXLUnrecognizedCompOperator,
	ExmiDXLValidationError,
	ExmiDXLXercesParseError,
	ExmiDXLIncorrectNumberOfChildren,
	ExmiDXL2PlStmtConversion,
	ExmiQuery2DXLAttributeNotFound,
	ExmiQuery2DXLUnsupportedFeature,
	ExmiQuery2DXLError,
	ExmiExpr2DXLUnsupportedFeature,
	ExmiExpr2DXLAttributeNotFound,
	ExmiDXL2PlStmtAttributeNotFound,
	ExmiDXL2ExprAttributeNotFound,

	// MD related errors
	ExmiMDCacheEntryDuplicate,
	ExmiMDCacheEntryNotFound,
	ExmiMDObjUnsupported,

	// GPDB-related exceptions
	ExmiGPDBError,

	// exceptions related to constant expression evaluation
	ExmiConstExprEvalNonConst,

	ExmiDXLSentinel
};

// message initialization for GPOS exceptions
void EresExceptionInit(gpos::CMemoryPool *mp);

}  // namespace gpdxl

#endif	// !DXL_exception_H


// EOF
