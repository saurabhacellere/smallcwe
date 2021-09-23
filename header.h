#include <iostream>

#include "IncorrectPtrScale_checker.h"
#pragma warning(push,0)
#include "logger.h"
#include "utility.h"
#include "CodeIssueWriter.hpp"
#include "GammaRuleFactory.h"
#pragma warning(pop)

using namespace std;
using namespace clang;

static const char* const SEVERITY = "high";
static const char* const RULE_KEY = "incorrect pointer scaling";
static const char* const ISSUE_DESC = "Incorrect pointer scaling can cause buffer overflow conditions. When performing pointer arithmetic, the size of the value to add to a pointer is automatically scaled to the size of the type of the pointed-to object.";

extern CodeIssueWriter codeIssueWriter;
static Acellere::Corona::CXX::Logger logger(Acellere::Corona::CXX::Logger::Category::CXXParser);

ADDTO_GAMMA_RULE_FACTORY_CTOR(RULE_KEY, IncorrectPtrScaleChecker)

void IncorrectPtrScaleChecker::onEndOfTranslationUnit(clang::ASTContext& pContext, IncorrectPtrScaleVisitor& pVisitor, std::vector<GammaASTBean>& pAstBeans)
{
	auto& SM = pContext.getSourceManager();
	auto& voilationSrcLocs = pVisitor.getViolationSrcLocations();
	for (const SourceLocation& srcLoc : voilationSrcLocs) {
		const string& fullPath = SM.getFilename(srcLoc);
		const string& relPath = Utility::GetRelativePath(fullPath);
		const size_t lineNum = SM.getPresumedLineNumber(srcLoc);
		codeIssueWriter.Write(relPath, ISSUE_DESC, RULE_KEY, SEVERITY, lineNum);
	}
}
