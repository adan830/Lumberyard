/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <CreateResourceDialog.h>
#include <QScopedPointer>

namespace Ui {
    class AddS3Bucket;
}

class AddS3Bucket
    : public CreateResourceDialog
{
public:

    AddS3Bucket(QWidget* parent, QSharedPointer<ICloudFormationTemplateModel> templateModel, ResourceManagementView* view);
    virtual ~AddS3Bucket() {}

    QString GetResourceType() const override { return "AWS::S3::Bucket"; }
    QString GetResourceName() const override;

protected:
    virtual bool TypeSpecificValidateResource(const QString& resourceName) override;

    QVariantMap GetVariantMap() const override;

private:
    QScopedPointer<Ui::AddS3Bucket> m_ui;
};


