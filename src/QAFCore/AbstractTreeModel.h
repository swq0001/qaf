/*!
 * \file AbstractTreeModel.h
 * \date 2016/01/16 14:25
 *
 * \author zxj
 * Contact: user@company.com
 *
 * \brief 
 *
 * ����Qt MVCģʽʵ�ֵ����νṹģ�ͣ�ʵ��������Ϊ��λ��ģ��
 * ���QStandardItem�Ե�Ԫ��Ϊ��λ��ģ�ͣ���ģ�͸������������Դ������
 *
 * \note
*/

#ifndef ABSTRACTTREEMODEL_H
#define ABSTRACTTREEMODEL_H

#include <QAbstractItemModel>
//#include <QMap>
#include <QStringList>

class ModelItem;

class AbstractTreeModel : public QAbstractItemModel
{
public:
	AbstractTreeModel(QObject *parent = NULL);
	virtual ~AbstractTreeModel();

	virtual int	rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual int	columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const;

	void setHeaders(QStringList headers);
	void addItem(ModelItem* item, ModelItem* parent = NULL);
	void insertItem(ModelItem* item, ModelItem* befor, ModelItem* parent = NULL);
	void removeItem(ModelItem* item,ModelItem* parent = NULL);

	QModelIndex indexForItem(ModelItem* item) const;
	ModelItem* itemForIndex(const QModelIndex& index) const;
	ModelItem* getRootItem() const;
private:
	//QMap<ModelItem*, ModelItem*> mItems;
	QStringList mHeaders;
	ModelItem* mRootItem = NULL;
};

#endif // ABSTRACTTREEMODEL_H