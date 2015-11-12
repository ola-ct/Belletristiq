/*
 * Copyright (c) 2015 Oliver Lau <oliver@ersatzworld.net>
 * All rights reserved.
 *
 */

#ifndef __MARKOVCHAIN_H_
#define __MARKOVCHAIN_H_


#include <QDebug>
#include <QVariantList>

#include "markovnode.h"


class MarkovChain {
public:
  typedef QList<MarkovNode*> MarkovNodeList;

  MarkovChain(void);

  void add(const QStringList &tokenList);
  const MarkovNodeList &nodes(void) const;
  void postProcess(void);
  void clear(void);

  int count(void) const;
  MarkovNode *at(int);

  void readFromTextFile(const QString &filename);
  void readFromJsonFile(const QString &filename);

  QVariantList toVariantList(void) const;

private:
  bool find(const QString &token, MarkovNodeList::iterator &i);
  int mCurrentNodeId;
  MarkovNodeList mNodeList;
};


QDebug operator<<(QDebug debug, const MarkovChain &chain);



#endif // __MARKOVCHAIN_H_

